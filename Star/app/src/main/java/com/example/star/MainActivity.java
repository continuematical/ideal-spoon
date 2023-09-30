package com.example.star;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.star.Voip.VoipCreateActivity;
import com.example.star.Voip.VoipListActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //初始化
        init();
    }

    private void init() {
        ((TextView) findViewById(R.id.title_text)).setText(R.string.app_name);
        ((TextView) findViewById(R.id.userinfo_id)).setText(MLOC.userId);
        findViewById(R.id.btn_main_im).setOnClickListener(this);
        findViewById(R.id.btn_main_voip).setOnClickListener(this);
        findViewById(R.id.btn_main_meeting).setOnClickListener(this);
        findViewById(R.id.btn_main_live).setOnClickListener(this);
        findViewById(R.id.btn_main_setting).setOnClickListener(this);
        findViewById(R.id.btn_main_class).setOnClickListener(this);
        findViewById(R.id.btn_main_audio).setOnClickListener(this);
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