package com.example.star.Voip;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import com.example.star.BaseActivity;
import com.example.star.HistoryBean;
import com.example.star.R;

import java.util.List;

public class VoipListActivity extends BaseActivity {
    private String mTargetID;
    private List<HistoryBean> mHistoryList;
    private ListView vHistoryList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_voip_list);

        init();
    }

    //初始化
    public void init() {
        ((TextView) findViewById(R.id.title_text)).setText("VOIP会话列表");
        findViewById(R.id.title_left_btn).setVisibility(View.VISIBLE);
        findViewById(R.id.title_right_btn).setOnClickListener(v -> finish());

        findViewById(R.id.create_btn).setOnClickListener(v -> startActivity(new Intent(VoipListActivity.this, VoipCreateActivity.class)));
    }

    public class MyListAdapter extends BaseAdapter {
        private LayoutInflater inflater;

        public MyListAdapter() {
            inflater = (LayoutInflater) getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        }

        @Override
        public int getCount() {
            if (mHistoryList != null) return mHistoryList.size();
            return 0;
        }

        @Override
        public Object getItem(int position) {
            if (mHistoryList == null) return null;
            return mHistoryList.get(position);
        }

        @Override
        public long getItemId(int position) {
            if (mHistoryList == null) return 0;
            return position;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            final ViewHolder itemHolder;
            if (convertView == null) {
                itemHolder = new ViewHolder();

            }
            return null;
        }
    }

    public class ViewHolder {
        public TextView vUserId;
        public TextView vTime;
        public TextView vCount;
        public View vHeadBg;
        public ImageView vHeadImage;
    }
}