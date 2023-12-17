package com.example.myapplication.base

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import butterknife.ButterKnife
import butterknife.Unbinder

abstract class BaseActivity : AppCompatActivity() {

    protected var unkinder: Unbinder? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        unkinder = ButterKnife.bind(this)
        setContentView(setLayoutId())
    }

    protected abstract fun setLayoutId(): Int
    protected abstract fun init()

}