package com.example.tiktok.fragment

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import com.example.tiktok.R
import com.example.tiktok.base.CommPagerAdapter
import com.example.tiktok.bean.BaseFragment
import com.example.tiktok.bean.MainPageChangeEvent
import com.example.tiktok.bean.VideoBean
import com.example.tiktok.databinding.FragmentPersonalHomeBinding
import com.example.tiktok.databinding.PersonalHomeHeaderBinding
import com.example.tiktok.utils.RxBus
import java.util.concurrent.Flow.Subscription

/**
 * 个人界面
 */

class PersonalHomeFragment : BaseFragment(), View.OnClickListener {
    lateinit var binding: FragmentPersonalHomeBinding
    private var pagerAdapter: CommPagerAdapter? = null
    private var curUserBean: VideoBean.UserBean? = null
    private var subscription: Subscription? = null

    /** 控件 **/
    private var ivReturn: ImageView? = null

    override fun init(inflater: LayoutInflater, container: ViewGroup?): View? {
        binding = FragmentPersonalHomeBinding.inflate(inflater, container, false)
        setInit()
        return binding.root
    }

    private fun setInit() {
        ivReturn = binding.ivReturn
        ivReturn!!.setOnClickListener(this)
    }

    /** 自动回顶部 **/
    private fun coordinatorLayoutBackTop() {

    }

    override fun onClick(v: View?) {
        when (v?.id) {
            R.id.ivReturn -> RxBus.getInstance().post(MainPageChangeEvent(0))
        }
    }

    override fun onDestroy() {
        super.onDestroy()

    }
}