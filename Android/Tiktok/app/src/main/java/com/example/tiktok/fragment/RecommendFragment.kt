package com.example.tiktok.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import androidx.recyclerview.widget.RecyclerView
import com.example.tiktok.activity.MainActivity
import com.example.tiktok.bean.BaseFragment
import com.example.tiktok.databinding.FragmentRecommendBinding
import com.example.tiktok.view.FullScreenVideoView


class RecommendFragment : BaseFragment() {
    /** 控件 */
    private lateinit var binding: FragmentRecommendBinding
    private var videoView: FullScreenVideoView? = null
    private var recyclerView: RecyclerView? = null

    /** 当前视频播放位置 */
    private var curPlayPos = -1

    private var ivCurCover: ImageView? = null

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentRecommendBinding.inflate(inflater, container, false)
        initView()
        return binding.root
    }

    private fun initView() {
        videoView = FullScreenVideoView(activity)
        recyclerView = binding.recyclerView
    }

    override fun onResume() {
        super.onResume()

        if (MainActivity.curMainPage == 0 && MainFragment.curPage == 1) videoView!!.start()
    }

    override fun onPause() {
        super.onPause()
        videoView!!.stopPlayback()
    }

    override fun onStop() {
        super.onStop()
        videoView!!.stopPlayback()
    }
}