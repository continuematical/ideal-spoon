package com.example.starrtc;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class StarRtcMainActivity extends BaseActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_star_rtc_main);
        init();
    }

    public void init() {
        ((TextView) findViewById(R.id.userinfo_id)).setText(MLOC.userId);
        findViewById(R.id.btn_main_audio).setOnClickListener(this);
        findViewById(R.id.btn_main_im).setOnClickListener(this);
        findViewById(R.id.btn_main_live).setOnClickListener(this);
        findViewById(R.id.btn_main_meeting).setOnClickListener(this);
        findViewById(R.id.btn_main_setting).setOnClickListener(this);
        findViewById(R.id.btn_main_voip).setOnClickListener(this);
    }

    @Override
    public void onBackPressed() {
        finish();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_main_voip:
                startActivity(new Intent(this, VoipListActivity.class));
                break;
        }
    }
}