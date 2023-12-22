package com.example.tiktok.activity

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.fragment.app.Fragment
import com.example.tiktok.R
import com.example.tiktok.base.BaseActivity
import com.example.tiktok.base.CommPagerAdapter

/**
 * 主页面
 */

class MainActivity : BaseActivity() {

    private var pagerAdapter: CommPagerAdapter? = null
    private var fragments = ArrayList<Fragment>()


    override fun getLayoutId(): Int {
        return R.layout.activity_main
    }

    override fun init() {

    }

}