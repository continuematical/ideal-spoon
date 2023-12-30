package com.example.tiktok.bean

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment

abstract class BaseFragment : Fragment() {
    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        var rootView = init(inflater, container)
        return rootView
    }

    abstract fun init(inflater: LayoutInflater, container: ViewGroup?): View?
}