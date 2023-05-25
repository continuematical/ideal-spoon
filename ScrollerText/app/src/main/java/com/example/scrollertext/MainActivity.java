package com.example.scrollertext;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.graphics.PixelFormat;
import android.os.Bundle;
import android.view.Gravity;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    LayoutParams mLayoutParams;
    WindowManager mWindowManager;
    private Button mButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mButton = new Button(getApplicationContext());
        /**
         * flags：
         *
         * FLAG_NOT_TOUCH_MODAL：将当前Windows区域之外的单击事件传递给底层的Window，
         * 以内的区域点击事件则自己处理；
         * FLAG_NOT_FOCUSABLE：不需要获取焦点，也不需要接收任何输入事件；
         * FLAG_SHOW_WHEN_LOCKED：开启此模式可以让Window显示在锁屏的界面上；
         *
         * types：表示Windows的类型
         */
        mLayoutParams = new LayoutParams(LayoutParams.WRAP_CONTENT,
                LayoutParams.WRAP_CONTENT,
                1, 0, PixelFormat.TRANSPARENT);
        mLayoutParams.flags = LayoutParams.FLAG_NOT_TOUCH_MODAL |
                LayoutParams.FLAG_NOT_FOCUSABLE |
                LayoutParams.FLAG_SHOW_WHEN_LOCKED;
        mLayoutParams.gravity = Gravity.LEFT | Gravity.TOP;
        mLayoutParams.x = 300;
        mLayoutParams.y = 300;
        mWindowManager = getWindowManager();
        mWindowManager.addView(mButton, mLayoutParams);

        Toast.makeText(this, "", Toast.LENGTH_SHORT).show();
    }
}