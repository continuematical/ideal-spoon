package android.bignerdranch.shmily;

import static android.app.Activity.RESULT_OK;

import android.Manifest;
import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.content.ContentUris;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.Nullable;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Toast;

public class WriteEnvelopeFragment extends Fragment implements View.OnClickListener {
    private static final int IMAGE_REQUEST_CODE = 0;

    private ImageButton preButton;
    private Button completed;
    private ImageView addPhoto;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @SuppressLint("MissingInflatedId")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_write_envelope, container, false);
        preButton = view.findViewById(R.id.pre_button);
        completed = view.findViewById(R.id.completed);
        addPhoto = view.findViewById(R.id.add_photo);

        preButton.setOnClickListener(this);
        completed.setOnClickListener(this);
        addPhoto.setOnClickListener(this);
        return view;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.pre_button:
                Intent returnEnvelope = new Intent(getActivity(), MyPostOfficeActivity.class);
                startActivity(returnEnvelope);
                break;
            case R.id.completed:
                break;
            case R.id.add_photo:
                Intent intent = new Intent(getActivity(), PhotoActivity.class);
                startActivity(intent);
//                Intent intent = new Intent(Intent.ACTION_PICK, null);
//                intent.setDataAndType(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, "image/*");
//                startActivityForResult(intent, IMAGE_REQUEST_CODE);
                break;
        }
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == IMAGE_REQUEST_CODE) {
            if (data != null) {
                Uri uri = data.getData();
                addPhoto.setImageURI(uri);
            }
        }
    }
}