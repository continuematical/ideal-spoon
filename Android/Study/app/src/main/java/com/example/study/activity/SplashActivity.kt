package com.example.study.activity

import android.content.Intent
import android.os.CountDownTimer
import android.view.View
import com.example.study.Base.BaseActivity
import com.example.study.databinding.ActivitySplashBinding

class SplashActivity : BaseActivity() {
    private lateinit var binding: ActivitySplashBinding

    override fun init(): View {
        binding = ActivitySplashBinding.inflate(layoutInflater)
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