package com.example.myapplication.activity

import android.annotation.SuppressLint
import android.content.Intent
import android.os.Bundle
import android.view.View
import android.view.View.OnClickListener
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity
import com.example.myapplication.R

class MainActivity : AppCompatActivity() {

    @SuppressLint("MissingInflatedId")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        findViewById<ImageView>(R.id.search_point).setOnClickListener(object : OnClickListener {
            override fun onClick(v: View?) {
                val intent = Intent(this@MainActivity, VideoListActivity().javaClass)
                startActivity(intent)
            }
        })
    }
}
