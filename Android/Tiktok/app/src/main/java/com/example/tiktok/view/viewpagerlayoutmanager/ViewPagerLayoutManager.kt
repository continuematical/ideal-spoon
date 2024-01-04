package com.example.tiktok.view.viewpagerlayoutmanager

import android.content.Context
import android.view.View
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.PagerSnapHelper
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.OnChildAttachStateChangeListener

class ViewPagerLayoutManager : LinearLayoutManager {
    private var mPagerSnapHelper: PagerSnapHelper? = null
    private var mOnViewPagerListener: OnViewPagerListener? = null
    private var recyclerView: RecyclerView? = null

    /** 位移 用来判断移动方向 **/
    private var mDrift = 0

    constructor(context: Context?) : super(context) {
        init()
    }

    constructor(context: Context?, orientation: Int, reverseLayout: Boolean) : super(
        context,
        orientation,
        reverseLayout
    ) {
        init()
    }

    private fun init() {
        mPagerSnapHelper = PagerSnapHelper()
    }

    override fun onAttachedToWindow(view: RecyclerView?) {
        super.onAttachedToWindow(view)
        mPagerSnapHelper!!.attachToRecyclerView(view)
        this.recyclerView = view
        recyclerView!!.addOnChildAttachStateChangeListener(mChildAttachStateChangeListener)
    }

    override fun onLayoutChildren(recycler: RecyclerView.Recycler?, state: RecyclerView.State?) {
        super.onLayoutChildren(recycler, state)
    }

    /**
     * 滑动状态的改变
     */
    override fun onScrollStateChanged(state: Int) {
        when (state) {
            RecyclerView.SCROLL_STATE_IDLE -> {
                val viewIdle = mPagerSnapHelper!!.findSnapView(this) ?: return
                val positionIdle = getPosition(viewIdle)
                if (mOnViewPagerListener != null && childCount == 1) {
                    mOnViewPagerListener!!.onPageSelected(
                        positionIdle,
                        positionIdle == itemCount - 1
                    )
                }
            }

            RecyclerView.SCROLL_STATE_DRAGGING -> {
                var viewDrag = mPagerSnapHelper!!.findSnapView(this)
                if (viewDrag != null) {
                    var positionDrag = getPosition(viewDrag)
                }
            }

            RecyclerView.SCROLL_STATE_SETTLING -> {
                var viewSetting = mPagerSnapHelper!!.findSnapView(this)
                if (viewSetting != null) {
                    var positionSettling = getPosition(viewSetting)
                }
            }
        }
    }

    /**
     * 设置竖直方向上的偏移量
     */
    override fun scrollVerticallyBy(
        dy: Int,
        recycler: RecyclerView.Recycler?,
        state: RecyclerView.State?
    ): Int {
        mDrift = dy
        return super.scrollVerticallyBy(dy, recycler, state)
    }

    /**
     * 监听水平方向上的相对偏移量
     */
    override fun scrollHorizontallyBy(
        dx: Int,
        recycler: RecyclerView.Recycler?,
        state: RecyclerView.State?
    ): Int {
        mDrift = dx
        return super.scrollHorizontallyBy(dx, recycler, state)
    }

    /**
     * 设置监听
     */
    private fun setOnViewPagerListener(listener: OnViewPagerListener?) {
        mOnViewPagerListener = listener
    }

    private val mChildAttachStateChangeListener: OnChildAttachStateChangeListener =
        object : OnChildAttachStateChangeListener {
            override fun onChildViewAttachedToWindow(view: View) {
                if (mOnViewPagerListener != null && childCount == 1) {
                    mOnViewPagerListener!!.onInitComplete()
                }
            }

            override fun onChildViewDetachedFromWindow(view: View) {
                if (mDrift >= 0) {
                    if (mOnViewPagerListener != null) mOnViewPagerListener!!.onPageRelease(
                        true,
                        getPosition(view)
                    ) else {
                        if (mOnViewPagerListener != null) mOnViewPagerListener!!.onPageRelease(
                            false,
                            getPosition(view)
                        )
                    }
                }

                mOnViewPagerListener!!.onPageRelease(true, getPosition(view))
            }
        }
}