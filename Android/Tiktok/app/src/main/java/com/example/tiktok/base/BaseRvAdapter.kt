package com.example.tiktok.base

import android.content.Context
import androidx.recyclerview.widget.RecyclerView

abstract class BaseRvAdapter<T, VH : BaseRvViewHolder?>(
    val context: Context,
    protected var datas: MutableList<T>
) : RecyclerView.Adapter<VH>() {

    override fun onBindViewHolder(holder: VH & Any, position: Int) {
        onBindData(holder, datas!![position], position)
    }

    override fun getItemCount(): Int {
        return if (datas == null) 0 else datas.size
    }

    protected abstract fun onBindData(holder: VH, data: T, position: Int)

    fun addData(data: T) {
        datas!!.add(data)
        notifyDataSetChanged()
    }

    fun addDataToPosition(data: T, position: Int) {
        datas!!.add(position, data)
        notifyDataSetChanged()
    }

    fun addData(data: List<T>) {
        val oldCount = datas!!.size
        datas!!.addAll(datas)
        notifyItemRangeInserted(oldCount, datas.size)
    }

    fun onlyRemoveItem(position: Int) {
        datas!!.removeAt(position)
    }

    fun clearData() {
        datas!!.clear()
        notifyDataSetChanged()
    }

}