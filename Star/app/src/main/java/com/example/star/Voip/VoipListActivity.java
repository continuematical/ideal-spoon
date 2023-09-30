package com.example.star.Voip;

import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import com.example.star.BaseActivity;
import com.example.star.DataBase.HistoryBean;
import com.example.star.R;
import com.example.star.UI.CircularCoverView;
import com.example.star.Utils.ColorUtils;

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
                convertView = inflater.inflate(R.layout.item_voip_list, null);

                itemHolder.vUserId = (TextView) convertView.findViewById(R.id.item_id);
                itemHolder.vCount = (TextView) convertView.findViewById(R.id.item_count);
                itemHolder.vHeadImage = (ImageView) convertView.findViewById(R.id.head_img);
                itemHolder.vHeadBg = convertView.findViewById(R.id.head_bg);
                itemHolder.vTime = (TextView) convertView.findViewById(R.id.item_time);
                itemHolder.vHeadCover = (CircularCoverView) convertView.findViewById(R.id.head_over);

                convertView.setTag(itemHolder);
            } else {
                itemHolder = (ViewHolder) convertView.getTag();
            }

            String userID = mHistoryList.get(position).getConversationID();
            itemHolder.vUserId.setText(userID);
            itemHolder.vHeadCover.setCoverColor(Color.parseColor("#ffffff"));
            itemHolder.vTime.setText(mHistoryList.get(position).getLastTime());
            itemHolder.vHeadBg.setBackgroundColor(ColorUtils.getColor(VoipListActivity.this, userID));

            if (mHistoryList.get(position).getNewMsgCount() == 0) {
                itemHolder.vCount.setVisibility(View.INVISIBLE);
            } else {
                itemHolder.vCount.setText("" + mHistoryList.get(position).getNewMsgCount());
                itemHolder.vCount.setVisibility(View.VISIBLE);
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
        public CircularCoverView vHeadCover;
    }
}