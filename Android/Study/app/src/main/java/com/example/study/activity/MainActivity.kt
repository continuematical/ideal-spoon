package com.example.study.activity

import android.view.View
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.viewpager.widget.ViewPager
import androidx.viewpager.widget.ViewPager.OnPageChangeListener
import com.example.study.Base.BaseActivity
import com.example.study.Base.CommonPagerAdapter
import com.example.study.databinding.ActivityMainBinding
import com.example.study.fragment.PersonalHomeFragment
import com.example.tiktok.fragment.MainFragment

class MainActivity : BaseActivity() {
    private lateinit var binding: ActivityMainBinding
    private var viewPager: ViewPager? = null
    private var pagerAdapter: CommonPagerAdapter? = null
    private var fragments = ArrayList<Fragment>()

    /** 页面 **/
    private var mainFragment = MainFragment()
    private var personalHomeFragment = PersonalHomeFragment()

    /** 上次点击返回键的时间 **/
    private var lastTime: Long = 0

    /** 连续点击返回键退出时间 **/
    private var EXIT_TIME = 2000

    override fun init(): View {
        binding = ActivityMainBinding.inflate(layoutInflater)
        viewPager = binding.viewPager
        /** 初始化页面 **/
        fragments.add(mainFragment)
        fragments.add(personalHomeFragment)
        pagerAdapter =
            CommonPagerAdapter(supportFragmentManager, fragments, arrayOf("", ""))
        viewPager!!.adapter = pagerAdapter
        viewPager!!.addOnPageChangeListener(object : OnPageChangeListener {
            override fun onPageScrolled(
                position: Int,
                positionOffset: Float,
                positionOffsetPixels: Int
            ) {
            }

            override fun onPageSelected(position: Int) {
                curMainPage = position
            }

            override fun onPageScrollStateChanged(state: Int) {}
        })
        return binding.root
    }

    /** 双击返回退出app **/
    override fun onBackPressed() {
        if (System.currentTimeMillis() - lastTime > EXIT_TIME) {
            if (viewPager!!.currentItem == 1) viewPager!!.currentItem = 0
            else {
                Toast.makeText(applicationContext, "再按一次退出", Toast.LENGTH_LONG)
                lastTime = System.currentTimeMillis()
            }
        } else {
            super.onBackPressed()
        }
    }

    companion object {
        var curMainPage = 0
    }
}