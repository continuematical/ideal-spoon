package com.example.tiktok.adapter;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.tiktok.base.BaseRvAdapter;
import com.example.tiktok.base.BaseRvViewHolder;
import com.example.tiktok.bean.VideoBean;

import java.util.List;

import butterknife.BindView;
import butterknife.ButterKnife;

public class GridVideoAdapter extends BaseRvAdapter<VideoBean, GridVideoAdapter.GridVideoViewHolder> {

    public GridVideoAdapter(@NonNull Context context, @NonNull List<VideoBean> datas) {
        super(context, datas);
    }

    @Override
    protected void onBindData(GridVideoViewHolder holder, VideoBean data, int position) {

    }

    @NonNull
    @Override
    public GridVideoViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return null;
    }

    public class GridVideoViewHolder extends BaseRvViewHolder {

        public GridVideoViewHolder(@Nullable View itemView) {
            super(itemView);

            ButterKnife.bind(this, itemView);
        }
    }
}
