package com.example.tiktok.fragment

import android.os.CountDownTimer
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.StaggeredGridLayoutManager
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout
import com.example.tiktok.R
import com.example.tiktok.adapter.GridVideoAdapter
import com.example.tiktok.bean.BaseFragment
import com.example.tiktok.bean.DataCreate
import com.example.tiktok.databinding.FragmentCurrentLocationBinding

class CurrentLocationFragment : BaseFragment() {
    private lateinit var binding: FragmentCurrentLocationBinding

    /** 组件 **/
    private var recyclerView: RecyclerView? = null
    private var adapter: GridVideoAdapter? = null
    private var refreshLayout: SwipeRefreshLayout? = null

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentCurrentLocationBinding.inflate(inflater, container, false)
        initView()
        return binding.root
    }

    private fun initView() {
        recyclerView = binding.recyclerView
        refreshLayout = binding.refreshLayout

        recyclerView!!.layoutManager =
            StaggeredGridLayoutManager(2, StaggeredGridLayoutManager.VERTICAL)
        adapter = GridVideoAdapter(context, DataCreate.data)
        recyclerView!!.adapter = adapter

        refreshLayout!!.setColorSchemeResources(R.color.color_link)
        refreshLayout!!.setOnRefreshListener {
            object : CountDownTimer(1000, 1000) {
                override fun onTick(millisUntilFinished: Long) {
                    TODO("Not yet implemented")
                }

                override fun onFinish() {
                    refreshLayout!!.isRefreshing = false
                }

            }
        }
    }
}