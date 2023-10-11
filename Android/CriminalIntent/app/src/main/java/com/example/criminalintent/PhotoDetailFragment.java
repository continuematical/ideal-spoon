package com.example.criminalintent;

import android.app.AlertDialog;
import android.app.Dialog;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.DialogFragment;

import java.io.File;

public class PhotoDetailFragment extends DialogFragment {
    private static String ARG_FILES = "files";
    ImageView mImageView;

    public static PhotoDetailFragment newInstance(File file) {
        Bundle args = new Bundle();
        args.putSerializable(ARG_FILES, file);

        PhotoDetailFragment fragment = new PhotoDetailFragment();
        fragment.setArguments(args);
        return fragment;
    }

    @NonNull
    @Override
    public Dialog onCreateDialog(@Nullable Bundle savedInstanceState) {
        File file = (File) getArguments().getSerializable(ARG_FILES);
        View v = LayoutInflater.from(getActivity()).inflate(R.layout.dialog_photo, null);
        mImageView = v.findViewById(R.id.crime_photo_detail);

        Bitmap bitmap = PictureUtils.getScaledBitmap(file.getPath(), getActivity());
        mImageView.setImageBitmap(bitmap);

        return new AlertDialog.Builder(getActivity())
                .setView(v)
                .setPositiveButton(android.R.string.ok, null)
                .create();
    }
}
