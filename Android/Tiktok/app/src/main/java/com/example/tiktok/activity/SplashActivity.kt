package com.example.tiktok.activity

import android.content.Intent
import com.example.tiktok.R
import com.example.tiktok.base.BaseActivity
import android.os.CountDownTimer

/**
 * 标志页
 */

class SplashActivity : BaseActivity() {
    override fun getLayoutId(): Int {
        return R.layout.activity_splash
    }

    override fun init() {
        setFullScreen()
        object : CountDownTimer(500, 500) {
            override fun onTick(millisUntilFinished: Long) {}
            override fun onFinish() {
                //startActivity(Intent(this@SplashActivity, MainActivity::class.java))
                //finish()
            }
        }.start()
    }
}