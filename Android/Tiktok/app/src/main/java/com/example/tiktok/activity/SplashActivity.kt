package com.example.tiktok.activity

import android.content.Intent
import com.example.tiktok.R
import com.example.tiktok.base.BaseActivity
import android.os.CountDownTimer
import android.view.View
import com.example.tiktok.databinding.ActivitySplashBinding

/**
 * 标志页
 */

class SplashActivity : BaseActivity() {
    private lateinit var binding: ActivitySplashBinding
    override fun init(): View {
        binding = ActivitySplashBinding.inflate(layoutInflater)
        setFullScreen()
        object : CountDownTimer(500, 500) {
            override fun onTick(millisUntilFinished: Long) {}
            override fun onFinish() {
                startActivity(Intent(this@SplashActivity, MainActivity::class.java))
                finish()
            }
        }.start()

        return binding.root
    }
}