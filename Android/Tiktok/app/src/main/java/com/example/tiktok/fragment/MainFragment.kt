package com.example.tiktok.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.viewpager.widget.ViewPager
import androidx.viewpager.widget.ViewPager.OnPageChangeListener
import com.example.tiktok.base.CommPagerAdapter
import com.example.tiktok.bean.BaseFragment
import com.example.tiktok.bean.PauseVideoEvent
import com.example.tiktok.databinding.FragmentMainBinding
import com.example.tiktok.utils.RxBus
import com.google.android.material.tabs.TabLayout

/**
 * 主页 Fragment
 */


class MainFragment : BaseFragment() {
    private lateinit var binding: FragmentMainBinding

    /** fragment **/
    private var currentLocationFragment: CurrentLocationFragment? = null
    private var recommendFragment: RecommendFragment? = null

    private var fragments = ArrayList<Fragment>()
    private var pagerAdapter: CommPagerAdapter? = null

    /** 页面控件 **/
    private var viewPager: ViewPager? = null
    private var tabMainMenu: TabLayout? = null
    private var tabTitle: TabLayout? = null


    private fun setFragments() {
        currentLocationFragment = CurrentLocationFragment()
        recommendFragment = RecommendFragment()

        /** 初始化 **/
        fragments.add(currentLocationFragment!!)
        fragments.add(recommendFragment!!)

        pagerAdapter = CommPagerAdapter(childFragmentManager, fragments, arrayOf("海淀", "推荐"))

        viewPager = binding!!.viewPager
        viewPager!!.adapter = pagerAdapter
        viewPager!!.addOnPageChangeListener(object : OnPageChangeListener {
            override fun onPageScrolled(
                position: Int,
                positionOffset: Float,
                positionOffsetPixels: Int
            ) {}

            override fun onPageSelected(position: Int) {
                curPage = position
                if (position == 1) {
                    //继续播放
                    RxBus.getInstance().post(PauseVideoEvent(true))
                } else {
                    RxBus.getInstance().post(PauseVideoEvent(false))
                }
            }

            override fun onPageScrollStateChanged(state: Int) {}

        })
    }

    private fun setMainMenu() {
        tabMainMenu = binding.tabMainMenu
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("首页"))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("好友"))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText(""))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("消息"))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("我"))
    }

    private fun setTabTitle() {
        tabTitle = binding.tabTitle
        tabTitle!!.addTab(tabTitle!!.newTab().setText("海淀"))
        tabTitle!!.addTab(tabTitle!!.newTab().setText("推荐"))
        tabTitle!!.setupWithViewPager(viewPager)
        tabTitle!!.getTabAt(1)!!.select()
    }

    companion object {
        var curPage = 1
    }

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View {
        binding = FragmentMainBinding.inflate(inflater, container, false)
        setFragments()
        setTabTitle()
        setMainMenu()
        return binding.root
    }
}