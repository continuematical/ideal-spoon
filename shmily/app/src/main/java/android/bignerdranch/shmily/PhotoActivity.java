package android.bignerdranch.shmily;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.ContentResolver;
import android.database.Cursor;
import android.icu.util.Measure;
import android.net.Uri;
import android.os.Bundle;
import android.os.Message;
import android.provider.MediaStore;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class PhotoActivity extends AppCompatActivity {
    List<String> filePath = new ArrayList<>();
    private GridView mGridView;
    private ImageButton preButton;
    private TextView select;
    private PhotoAdapter mPhotoAdapter;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_photo);
        searchPhoto();
        mGridView = findViewById(R.id.photo_list_grid_view);
        preButton = findViewById(R.id.pre_button);
        select = findViewById(R.id.select);
        updateView();
    }

    public void searchPhoto() {
        filePath.clear();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Uri ImageUri = MediaStore.Images.Media.EXTERNAL_CONTENT_URI;
                ContentResolver resolver = getContentResolver();
                Cursor cursor = resolver.query(ImageUri, null,
                        MediaStore.Images.Media.MIME_TYPE + "=? or "
                                + MediaStore.Images.Media.MIME_TYPE + "=? " + "or "
                                +MediaStore.Images.Media.MIME_TYPE + "=?"
                        , new String[]{"image/jpeg", "image/jpg", "image/png"},
                        MediaStore.Images.Media.DATE_MODIFIED);
                while (cursor.moveToNext()) {
                    @SuppressLint("Range") String path = cursor.getString(cursor.getColumnIndex(MediaStore.Images.Media.DATA));
                    filePath.add(path);
                }
                cursor.close();
            }
        }).start();
    }

    public void updateView() {
        if (mPhotoAdapter == null) {
            mPhotoAdapter = new PhotoAdapter(PhotoActivity.this, filePath);
            mGridView.setAdapter(mPhotoAdapter);
        } else {
            mPhotoAdapter.setPhotos(filePath);
            mPhotoAdapter.notifyDataSetChanged();
        }
    }
}