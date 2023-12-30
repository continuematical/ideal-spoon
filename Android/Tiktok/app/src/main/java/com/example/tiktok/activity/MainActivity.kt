package com.example.tiktok.activity

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.viewpager.widget.ViewPager
import androidx.viewpager.widget.ViewPager.OnPageChangeListener
import com.example.tiktok.R
import com.example.tiktok.base.BaseActivity
import com.example.tiktok.base.CommPagerAdapter
import com.example.tiktok.bean.PauseVideoEvent
import com.example.tiktok.databinding.ActivityMainBinding
import com.example.tiktok.fragment.MainFragment
import com.example.tiktok.utils.RxBus

/**
 * 主页面
 */

class MainActivity : BaseActivity() {

    private lateinit var binding: ActivityMainBinding
    private var viewPager: ViewPager? = null
    private var pagerAdapter: CommPagerAdapter? = null
    private var fragments = ArrayList<Fragment>()

    /** fragment页面 **/
    private var mainFragment = MainFragment()
    //private var personalHomeFragment = PersonalHomeFragment()

    /** 上次点击返回键的时间 **/
    private var lastTime: Long = 0

    /** 连续按返回键退出时间  */
    private val EXIT_TIME = 2000
    override fun init(): View {
        try {
            Thread.sleep(2000)
        } catch (e: Exception) {
            e.printStackTrace()
        }

        binding = ActivityMainBinding.inflate(layoutInflater)
        viewPager = binding.viewPager
        /** 初始化页面 **/
        fragments.add(mainFragment)
        //fragments.add(personalHomeFragment)

        pagerAdapter = CommPagerAdapter(supportFragmentManager, fragments, arrayOf("", ""))
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
                if (position == 0) {
                    RxBus.getInstance().post(PauseVideoEvent(true))
                } else {
                    RxBus.getInstance().post(PauseVideoEvent(false))
                }
            }

            override fun onPageScrollStateChanged(state: Int) {

            }

        })

        return binding.root
    }


    /** 双击返回退出APP **/
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