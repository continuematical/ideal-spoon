package com.example.scrollertext;

import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.os.Bundle;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private ScrollerLinearLayout mLayout;
    private Button mButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mLayout = findViewById(R.id.layout);
        mButton = findViewById(R.id.button);
        mButton.setOnClickListener(v -> {
            mLayout.smoothScroll(-400, 0);
        });
    }
}