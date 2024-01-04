package com.example.tiktok.base

import android.content.Context
import androidx.recyclerview.widget.RecyclerView

abstract class BaseRvAdapter<T, VH : BaseRvViewHolder?>(
    val context: Context?,
    private var data: ArrayList<T>
) : RecyclerView.Adapter<VH>() {

    override fun onBindViewHolder(holder: VH & Any, position: Int) {
        onBindData(holder, data[position], position)
    }

    override fun getItemCount(): Int {
        return if (data == null) 0 else data.size
    }

    protected abstract fun onBindData(holder: VH, data: T, position: Int)

    fun addData(data: T) {
        this.data!!.add(data)
        notifyDataSetChanged()
    }

    fun addDataToPosition(data: T, position: Int) {
        this.data!!.add(position, data)
        notifyDataSetChanged()
    }

    fun addData(data: List<T>) {
        val oldCount = this.data!!.size
        this.data!!.addAll(this.data)
        notifyItemRangeInserted(oldCount, this.data.size)
    }

    fun onlyRemoveItem(position: Int) {
        data!!.removeAt(position)
    }

    fun clearData() {
        data!!.clear()
        notifyDataSetChanged()
    }

}