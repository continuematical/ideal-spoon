package com.example.tiktok.adapter

import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import com.example.tiktok.R
import com.example.tiktok.activity.PlayListActivity
import com.example.tiktok.adapter.GridVideoAdapter.GridVideoViewHolder
import com.example.tiktok.base.BaseRvAdapter
import com.example.tiktok.base.BaseRvViewHolder
import com.example.tiktok.bean.VideoBean
import com.example.tiktok.databinding.ItemGridvideoBinding
import com.example.tiktok.view.IconFontTextView

class GridVideoAdapter(context: Context?, data: ArrayList<VideoBean?>) :
    BaseRvAdapter<VideoBean?, GridVideoViewHolder?>(context, data) {

    override fun onBindData(holder: GridVideoViewHolder?, data: VideoBean?, position: Int) {
        holder!!.ivCover!!.setBackgroundResource(data!!.coverRes)
        holder.tvContent!!.text = data.content
        holder.tvDistance!!.text = data.distance.toString() + "km"
        holder.ivHead!!.setImageResource(data.userBean!!.head)

        holder.itemView.setOnClickListener {
            PlayListActivity.initPos = position
            context?.startActivity(Intent(context, PlayListActivity::class.java))
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): GridVideoViewHolder {
        val view = LayoutInflater.from(context).inflate(R.layout.item_gridvideo, parent, false)
        return GridVideoViewHolder(view)
    }

    inner class GridVideoViewHolder(itemView: View?) : BaseRvViewHolder(itemView) {
        private var binding: ItemGridvideoBinding =
            ItemGridvideoBinding.inflate(LayoutInflater.from(context))
        var ivCover: ImageView? = null
        var tvContent: TextView? = null
        var tvDistance: IconFontTextView? = null
        var ivHead: ImageView? = null

        init {
            ivCover = binding.ivCover
            tvContent = binding.tvContent
            tvDistance = binding.tvDistance
            ivHead = binding.ivHead
        }
    }
}