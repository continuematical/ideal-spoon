package com.example.tiktok.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.viewpager.widget.ViewPager
import androidx.viewpager.widget.ViewPager.OnPageChangeListener
import com.example.study.Base.BaseFragment
import com.example.study.Base.CommonPagerAdapter
import com.example.study.databinding.FragmentMainBinding
import com.example.study.fragment.BookFragment
import com.example.study.fragment.FirstFragment
import com.example.study.fragment.RecommendFragment
import com.google.android.material.tabs.TabLayout

/**
 * 主页 Fragment
 */


class MainFragment : BaseFragment() {
    private lateinit var binding: FragmentMainBinding

    /** fragment **/
    private var bookFragment: BookFragment? = null
    private var recommendFragment: RecommendFragment? = null
    private var firstFragment: FirstFragment? = null

    private var fragments = ArrayList<Fragment>()
    private var pagerAdapter: CommonPagerAdapter? = null

    /** 页面控件 **/
    private var viewPager: ViewPager? = null
    private var tabMainMenu: TabLayout? = null
    private var tabTitle: TabLayout? = null


    private fun setFragments() {
        bookFragment = BookFragment()
        recommendFragment = RecommendFragment()
        firstFragment = FirstFragment()

        /** 初始化 **/
        fragments.add(firstFragment!!)
        fragments.add(bookFragment!!)
        fragments.add(recommendFragment!!)

        pagerAdapter =
            CommonPagerAdapter(childFragmentManager, fragments, arrayOf("首页", "图书", "推荐"))

        viewPager = binding!!.viewPager
        viewPager!!.adapter = pagerAdapter
        viewPager!!.addOnPageChangeListener(object : OnPageChangeListener {
            override fun onPageScrolled(
                position: Int,
                positionOffset: Float,
                positionOffsetPixels: Int
            ) {
            }

            override fun onPageSelected(position: Int) {
                curPage = position
            }

            override fun onPageScrollStateChanged(state: Int) {}

        })
    }

    private fun setMainMenu() {
        tabMainMenu = binding.tabMainMenu
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("首页"))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("课程"))
        tabMainMenu!!.addTab(tabMainMenu!!.newTab().setText("我的"))
    }

    private fun setTabTitle() {
        tabTitle = binding.tabTitle
        tabTitle!!.addTab(tabTitle!!.newTab().setText("首页"))
        tabTitle!!.addTab(tabTitle!!.newTab().setText("图书"))
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