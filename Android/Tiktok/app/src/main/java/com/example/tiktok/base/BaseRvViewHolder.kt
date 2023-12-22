package com.example.tiktok.base

import android.view.View
import androidx.recyclerview.widget.RecyclerView
import butterknife.ButterKnife

open class BaseRvViewHolder(itemView: View?) : RecyclerView.ViewHolder(itemView!!) {
    init {
        ButterKnife.bind(this, itemView!!)
    }
}