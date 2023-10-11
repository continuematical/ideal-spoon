package com.example.criminalintent;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.provider.MediaStore;
import android.text.Editable;
import android.text.TextWatcher;
import android.text.format.DateFormat;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;

import androidx.core.content.FileProvider;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.io.File;
import java.util.Date;
import java.util.List;
import java.util.UUID;

public class CrimeFragment extends Fragment {

    private static final String AGR_CRIME_ID = "crime_id";
    private static final String DIALOG_DATE = "dialog_date";
    private static final int REQUEST_DATE = 0;
    private static final int REQUEST_CONTACT = 1;
    private static final int REQUEST_PHOTO = 2;

    private Crime mCrime;
    private EditText mTitleField;
    private Button mDateButton;
    private CheckBox mSolvedCheckBox;
    private Button mReportButton;
    private Button mSuspectButton;
    private Button mCallButton;
    private File mPhotoFile;

    private ImageView mImageView;

    public static CrimeFragment newInstance(UUID crimeID) {
        Bundle args = new Bundle();
        args.putSerializable(AGR_CRIME_ID, crimeID);
        CrimeFragment fragment = new CrimeFragment();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    //必须为公共方法，受activity调用
    public void onCreate(Bundle saveInstance) {
        super.onCreate(saveInstance);
        UUID crimeID = (UUID) getArguments().getSerializable(AGR_CRIME_ID);
        mCrime = CrimeLab.get(getActivity()).getCrime(crimeID);
        mPhotoFile = CrimeLab.get(getActivity()).getPhotoFile(mCrime);
        setHasOptionsMenu(true);
    }

    @Override
    public void onCreateOptionsMenu(@NonNull Menu menu, @NonNull MenuInflater inflater) {
        super.onCreateOptionsMenu(menu, inflater);
        inflater.inflate(R.menu.fragment_crime, menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.delete_crime:
                CrimeLab lab = CrimeLab.get(getActivity());
                lab.deleteCrime(mCrime);
                getActivity().finish();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public void onPause() {
        super.onPause();
        CrimeLab.get(getActivity()).updateCrime(mCrime);
    }


    @Override
    public void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (resultCode != Activity.RESULT_OK) {
            return;
        }
        if (requestCode == REQUEST_DATE) {
            Date date = (Date) data.getSerializableExtra(DatePickerFragment.EXTRA_DATE);
            mCrime.setDate(date);
            mDateButton.setText(mCrime.getDate().toString());
        } else if (requestCode == REQUEST_CONTACT && data != null) {
            Uri contactUri = data.getData();
            String[] contactsName = new String[]{ContactsContract.Contacts.DISPLAY_NAME};
            Cursor c = getActivity().getContentResolver()
                    .query(contactUri, contactsName, null, null, null);
            try {
                if (c.getCount() == 0) {
                    return;
                }
                c.moveToFirst();
                String suspect = c.getString(0);
                mCrime.setSuspect(suspect);
                mSuspectButton.setText(suspect);
            } finally {
                c.close();
            }
        } else if (requestCode == REQUEST_PHOTO) {
            Uri uri = FileProvider.getUriForFile(getActivity(),
                    "com.example.criminalintent.fileprovider",
                    mPhotoFile);
            getActivity().revokeUriPermission(uri,
                    Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            updatePhotoView();
        }
    }

    @SuppressLint("MissingInflatedId")
    @Override
    //创建和配置fragment视图
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle saveInstance) {
        View v = inflater.inflate(R.layout.fragment_crime, container, false);
        //从指定的xml资源扩展一个新的层次视图结构
        //EditText
        mTitleField = v.findViewById(R.id.crime_title);
        mTitleField.setText(mCrime.getTitle());
        //文件存储方式
//        String text=load(getActivity(),"data");
//        if(!TextUtils.isEmpty(text)){
//            mCrime.setTitle(text);
//            mTitleField.setSelection(text.length());
//        }
        mTitleField.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                mCrime.setTitle(charSequence.toString());
                //代表用户输入
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        //button
        mDateButton = v.findViewById(R.id.crime_date);
        mDateButton.setText(mCrime.getDate().toString());
        mDateButton.setOnClickListener(view -> {
            FragmentManager manager = getFragmentManager();
            DatePickerFragment datePickerFragment = DatePickerFragment.newInstance(mCrime.getDate());
            datePickerFragment.setTargetFragment(CrimeFragment.this, REQUEST_DATE);
            datePickerFragment.show(manager, DIALOG_DATE);
        });

        //mReportButton
        mReportButton = v.findViewById(R.id.crime_report);
        mReportButton.setOnClickListener(v13 -> {
            Intent i = new Intent(Intent.ACTION_SEND);
            i.setType("text/plain");
            i.putExtra(Intent.EXTRA_TEXT, getCrimeReport());
            i.putExtra(Intent.EXTRA_SUBJECT, getString(R.string.crime_report_subject));
            //每次都出现activity选择器
            i.createChooser(i, getString(R.string.send_report));
            startActivity(i);
        });

        //mSuspectButton
        final Intent pickContact = new Intent(Intent.ACTION_PICK, ContactsContract.Contacts.CONTENT_URI);
        mSuspectButton = v.findViewById(R.id.crime_suspect);
        mSuspectButton.setOnClickListener(v1 -> startActivityForResult(pickContact, REQUEST_CONTACT));

        if (mCrime.getSuspect() != null) {
            mSuspectButton.setText(mCrime.getSuspect());
        }

        //确认是否有响应相机的activity
        PackageManager packageManager = getActivity().getPackageManager();
        if (packageManager.resolveActivity(pickContact, PackageManager.MATCH_DEFAULT_ONLY) == null) {
            mSuspectButton.setEnabled(false);
        }

        //触发拍照
        //默认只能拍摄缩略图，并且保存在Intent中
        final Intent capturePicture = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        boolean canTakePhoto = mPhotoFile != null && capturePicture.resolveActivity(packageManager) != null;
        mImageView.setEnabled(canTakePhoto);

        mImageView = v.findViewById(R.id.photo);
        mImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //将本地路径转化为Uri形式
                Uri uri = FileProvider.getUriForFile(getActivity()
                        , "com.example.criminalintent.fileprovider", mPhotoFile);
                //指向存储路径的Uri
                capturePicture.putExtra(MediaStore.EXTRA_OUTPUT, uri);

                //通过AndroidManifest.xml的<intent> tags过滤intent
                List<ResolveInfo> cameraActivities = getActivity().getPackageManager()
                        .queryIntentActivities(capturePicture, PackageManager.MATCH_DEFAULT_ONLY);
                for (ResolveInfo activity : cameraActivities) {
                    //实际写入文件需要给予相机权限
                    //给所有符合条件的activity应用权限
                    getActivity().grantUriPermission(activity.activityInfo.packageName, uri
                            , Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
                }
                startActivityForResult(capturePicture, REQUEST_PHOTO);
            }
        });

        //mCallButton
        mCallButton = v.findViewById(R.id.crime_call);
        mCallButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

            }
        });

        //mImageView
        mImageView = v.findViewById(R.id.photo);

        //CheckBox
        mSolvedCheckBox = v.findViewById(R.id.crime_solved);
        mSolvedCheckBox.setChecked(mCrime.isSolved());
        mSolvedCheckBox.setOnCheckedChangeListener((compoundButton, b) -> mCrime.setSolved(b));
        return v;
    }

    private String getCrimeReport() {
        String solveString = null;
        if (mCrime.isSolved()) {
            solveString = getString(R.string.crime_report_solved);
        } else {
            solveString = getString(R.string.crime_report_unsolved);
        }

        String dateFormat = "EEE,MMM dd";
        String dateString = DateFormat.format(dateFormat, mCrime.getDate()).toString();
        String suspect = mCrime.getSuspect();
        if (suspect != null) {
            suspect = getString(R.string.crime_report_suspect);
        } else {
            suspect = getString(R.string.crime_report_no_suspect);
        }
        String report = getString(R.string.crime_report, mCrime.getTitle(), solveString, dateString, suspect);
        return report;
    }

    //刷新photo视图方法
    private void updatePhotoView() {
        if (mPhotoFile == null || !mPhotoFile.exists()) {
            mImageView.setImageDrawable(null);
        } else {
            Bitmap bitmap = PictureUtils.getScaledBitmap(mPhotoFile.getPath()
                    , getActivity());
            mImageView.setImageBitmap(bitmap);
        }
    }
}
