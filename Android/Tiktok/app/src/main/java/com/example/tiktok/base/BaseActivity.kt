package com.example.tiktok.base

import android.os.Bundle
import android.os.PersistableBundle
import android.view.View
import android.view.WindowManager
import androidx.appcompat.app.AppCompatActivity

/**
 * 基本页面
 */

abstract class BaseActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(init())
    }

    protected abstract fun init(): View

    /**
     * 设置状态栏颜色
     */
    protected fun setSystemBarColor(color: Int) {
        //ImmersionBar.with(this).statusBarColor(color)
    }

    /**
     * 去除状态栏
     */
    protected fun hideStatusBar() {
        //ImmersionBar.with(this).hideBar(BarHide.FLAG_HIDE_STATUS_BAR).init()
    }

    /**
     * 保持不息屏
     */
    protected fun keepScreenOn() {
        window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)
    }

    /**
     * Activity退出动画
     */
    protected fun setExitAnimation(animId: Int) {
        overridePendingTransition(0, animId)
    }

    /**
     * 全屏
     */
    protected fun setFullScreen() {
        //ImmersionBar.with(this).init()
    }
}