package com.example.study.fragment

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.study.Base.BaseFragment
import com.example.study.R
import com.example.study.databinding.FragmentBookBinding

class BookFragment : BaseFragment() {
    private lateinit var binding: FragmentBookBinding

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentBookBinding.inflate(layoutInflater)
        return binding.root
    }
}