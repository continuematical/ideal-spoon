package com.example.tiktok.fragment

import androidx.fragment.app.Fragment
import butterknife.BindView
import com.example.tiktok.R
import com.example.tiktok.base.BaseFragment
import com.example.tiktok.base.CommPagerAdapter

/**
 * 主页 Fragment
 */

class MainFragment : BaseFragment() {

    private var currentLocationFragment: CurrentLocationFragment? = null

    private var fragments = ArrayList<Fragment>()
    private var pagerAdapter: CommPagerAdapter? = null

    override fun setLayoutId(): Int {
        return R.layout.fragment_main
    }

    override fun init() {
        setFragments()
    }

    private fun setFragments() {
        currentLocationFragment = CurrentLocationFragment()

        fragments.add(currentLocationFragment!!)

        pagerAdapter = CommPagerAdapter(childFragmentManager, fragments, arrayOf("海淀"))

    }

    private fun setMainMenu() {

    }

    companion object {
        var curPage = 1
    }

}