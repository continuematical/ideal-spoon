package com.example.myapplication.activity

import android.graphics.drawable.VectorDrawable
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.myapplication.R
import com.example.myapplication.bean.Video

class VideoListActivity : AppCompatActivity() {

    private val video_list = ArrayList<Video>()
    private lateinit var adapter: VideoAdapter
    private lateinit var recycler: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_video_list)
        initData()
        showList()
    }

    private fun initData() {
        video_list.add(Video("小学五年级数学:十以内...", R.drawable.img1, "07:44"))
        video_list.add(Video("秒杀名师:数的乘法", R.drawable.img2, "03:44"))
        video_list.add(Video("小学一年级数学:10以内...", R.drawable.img3, "08:03"))
        video_list.add(Video("十的乘法巧算速算", R.drawable.img4, "03:15"))
        video_list.add(Video("小学数学培优:乘法的简便...", R.drawable.img5, "03:05"))
        video_list.add(Video("数学启蒙", R.drawable.img6, "09:48"))
    }

    private fun showList() {
        var linearLayout = LinearLayoutManager(this)
        linearLayout.orientation = LinearLayoutManager.VERTICAL
        recycler = findViewById(R.id.recycler)
        recycler.layoutManager = linearLayout

        adapter = VideoAdapter(video_list)
        recycler.adapter = adapter
    }
}