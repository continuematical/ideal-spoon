package com.example.study.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.study.Base.BaseFragment
import com.example.study.databinding.FragmentRecommandBinding

class RecommendFragment : BaseFragment() {
    private lateinit var binding: FragmentRecommandBinding

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentRecommandBinding.inflate(layoutInflater)
        return binding.root
    }
}