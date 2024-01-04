package com.example.tiktok.adapter

import android.content.Context
import android.view.View
import android.view.ViewGroup
import com.example.tiktok.base.BaseRvAdapter
import com.example.tiktok.base.BaseRvViewHolder
import com.example.tiktok.bean.VideoBean

class VideoAdapter(context: Context?, data: ArrayList<VideoBean>) :
    BaseRvAdapter<VideoBean, VideoAdapter.VideoViewHolder?>(context, data) {
    inner class VideoViewHolder(itemView: View?) : BaseRvViewHolder(itemView) {
        init {

        }
    }

    override fun onBindData(holder: VideoViewHolder?, data: VideoBean, position: Int) {
        TODO("Not yet implemented")
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): VideoViewHolder {
        TODO("Not yet implemented")
    }
}