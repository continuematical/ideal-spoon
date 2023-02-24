package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.ContentUris;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.UUID;

public class WriteInterestActivity extends AppCompatActivity implements View.OnClickListener {
    private static final int IMAGE_REQUEST_CODE = 0;
    public static final String EXTRA_INTEREST_ID = "interest_id";

    private EditText mTitle;
    private EditText mText;
    private ImageView mAdd;
    private Button completed;
    private Interest mInterest;
    private ImageButton preButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_write_interest);
        mInterest = new Interest();

        mTitle = findViewById(R.id.input_title);
        mText = findViewById(R.id.input_text);
        mAdd = findViewById(R.id.add_photo);
        completed = findViewById(R.id.completed);
        preButton = findViewById(R.id.pre_button);

        mTitle.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                mInterest.setTitle(charSequence.toString());
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        mText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                mInterest.setText(charSequence.toString());
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        completed.setOnClickListener(this);
        mAdd.setOnClickListener(this);
        preButton.setOnClickListener(this);
    }

    public boolean JudgementIfBlank() {
        if (mInterest.getTitle() == null) {
            Toast.makeText(this, R.string.please_input_title, Toast.LENGTH_SHORT).show();
            return false;
        }
        if (mInterest.getText() == null) {
            Toast.makeText(this, R.string.please_input_text, Toast.LENGTH_SHORT).show();
            return false;
        }
        if (mInterest.getUri() == null) {
            Toast.makeText(this, R.string.please_choose_picture, Toast.LENGTH_SHORT).show();
            return false;
        }
        return true;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.add_photo:
                Intent intent = new Intent(Intent.ACTION_PICK, null);
                intent.setDataAndType(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, "image/*");
                startActivityForResult(intent, IMAGE_REQUEST_CODE);
                break;
            case R.id.completed:
                if (JudgementIfBlank()) {
                    InterestLab.get(WriteInterestActivity.this).addInterest(mInterest);
                    Intent completed = new Intent(WriteInterestActivity.this, InterestListActivity.class);
                    startActivity(completed);
                }
                break;
            case R.id.pre_button:
                Intent returnPostOffice = new Intent(WriteInterestActivity.this, InterestListActivity.class);
                startActivity(returnPostOffice);
                break;
        }
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == IMAGE_REQUEST_CODE) {
            if (data != null) {
                Uri uri = data.getData();
                mAdd.setImageURI(uri);
                mInterest.setUri(uri);
            }
        }
    }

    public static Intent newInstance(Context context, UUID interestID) {
        Intent intent = new Intent(context, LookInterestActivity.class);
        intent.putExtra(EXTRA_INTEREST_ID, interestID);
        return intent;
    }
}
