package com.example.study.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.study.Base.BaseFragment
import com.example.study.databinding.FragmentFirstBinding

class FirstFragment : BaseFragment() {
    private lateinit var binding: FragmentFirstBinding
    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentFirstBinding.inflate(layoutInflater)
        return binding.root
    }
}