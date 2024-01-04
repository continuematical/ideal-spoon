package com.example.tiktok.view

import android.content.Context
import android.util.AttributeSet
import android.view.GestureDetector
import android.view.GestureDetector.SimpleOnGestureListener
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import android.view.animation.AnimationSet
import android.widget.ImageView
import android.widget.RelativeLayout
import com.example.tiktok.R
import kotlin.random.Random

class LikeView : RelativeLayout {
    /** 手势 **/
    private var gestureDetector: GestureDetector? = null

    /** 图片大小 **/
    private val likeViewSize = 330
    private val angles = intArrayOf(-30, 0, 30)

    /** 单击是否有点赞效果 **/
    private val canSingleTabShow = false
    private var onLikeListener: OnLikeListener? = null
    private var onPlayPauseListener: OnPlayPauseListener? = null

    constructor(context: Context?) : super(context) {
        init()
    }

    constructor(context: Context?, attrs: AttributeSet?) : super(context, attrs) {
        init()
    }

    private fun init() {
        gestureDetector = GestureDetector(object : SimpleOnGestureListener() {
            override fun onDoubleTap(e: MotionEvent): Boolean {
                addLikeView(e)
                return super.onDoubleTap(e)
            }

            override fun onSingleTapConfirmed(e: MotionEvent): Boolean {
                return super.onSingleTapConfirmed(e)
            }
        })
    }

    private fun addLikeView(e: MotionEvent) {
        val imageView = ImageView(context)
        imageView.setImageResource(R.mipmap.ic_like)
        addView(imageView)

        val layoutParams = LayoutParams(likeViewSize, likeViewSize)
        layoutParams.leftMargin = e.x.toInt() - likeViewSize / 2
        layoutParams.rightMargin = e.y.toInt() - likeViewSize / 2
        imageView.layoutParams = layoutParams
        playAnim(imageView)
    }

    /**
     * 点赞动画
     */
    private fun playAnim(view: View) {
        val animationSet = AnimationSet(true)
        val degrees = angles[Random.nextInt()]


    }

    interface OnLikeListener {
        fun onLikeListener()
    }

    /**
     * 设置双击点赞
     */
    fun setOnLikeListener(onLikeListener: OnLikeListener?) {
        this.onLikeListener = onLikeListener
    }

    interface OnPlayPauseListener {
        fun OnPlayPauseListener()
    }

    /**
     * 设置单击播放暂停
     */
    fun setOnPlayPauseListener(onPlayPauseListener: OnPlayPauseListener?) {
        this.onLikeListener = onLikeListener
    }
}