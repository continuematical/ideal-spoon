package com.example.tiktok.activity

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.fragment.app.Fragment
import com.example.tiktok.R
import com.example.tiktok.base.BaseActivity
import com.example.tiktok.base.CommPagerAdapter
import com.example.tiktok.fragment.MainFragment

/**
 * 主页面
 */

class MainActivity : BaseActivity() {

    private var pagerAdapter: CommPagerAdapter? = null
    private var fragments = ArrayList<Fragment>()

    private var mainFragment = MainFragment()

    /** 上次点击返回键的时间 **/
    private var lastTime: Long = 0

    /** 连续按返回键退出时间  */
    private val EXIT_TIME = 2000

    override fun getLayoutId(): Int {
        return R.layout.activity_main
    }

    override fun init() {
        try {
            Thread.sleep(2000)
        } catch (e: Exception) {
            e.printStackTrace()
        }

        fragments.add(mainFragment)

        pagerAdapter = CommPagerAdapter(supportFragmentManager, fragments, arrayOf("", ""))

    }

    /** 双击返回退出APP **/
    override fun onBackPressed() {
        if (System.currentTimeMillis() - lastTime > EXIT_TIME) {

        } else {
            super.onBackPressed()
        }
    }

    companion object {
        var curMainPage = 0
    }

}