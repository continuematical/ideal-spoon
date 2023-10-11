package com.example.photogalley;

import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.io.IOException;

public class PhotoGalleyFragment extends Fragment {
    private RecyclerView mRecyclerView;

    public static Fragment newInstance() {
        return new PhotoGalleyFragment();
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //保留fragment
        setRetainInstance(true);
        new FetchItemsTasks().execute();//启动AsyncTask
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_photo_galley, container, false);
        mRecyclerView = view.findViewById(R.id.photo_recycler_view);
        mRecyclerView.setLayoutManager(new GridLayoutManager(getActivity(), 3));
        return view;
    }

    //使用后台线程获取目标网站获取数据并记录日志
    private class FetchItemsTasks extends AsyncTask<Void, Void, Void> {
        private static final String TAG = "PhotoGalleryFragment";

        @Override
        protected Void doInBackground(Void... params) {
            try {
                String result = new FlickerFetchr().getUriString("https://huaban.com");
                Log.i(TAG, "Fetched contents of URL:" + result);
            } catch (IOException e) {
                Log.e(TAG, "Failed to fetch URL:", e);
            }

            return null;
        }
    }
}
