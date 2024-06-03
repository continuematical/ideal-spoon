package com.example.tiktok.view

import android.content.Context
import android.os.Handler
import android.util.AttributeSet
import android.view.GestureDetector
import android.view.GestureDetector.SimpleOnGestureListener
import android.view.MotionEvent
import android.view.View
import android.view.animation.Animation
import android.view.animation.AnimationSet
import android.widget.ImageView
import android.widget.RelativeLayout
import com.example.tiktok.R
import com.example.tiktok.utils.AnimUtils
import kotlin.random.Random

/**
 * 点赞动画
 */

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
                onLikeListener!!.onLikeListener()
                return true
            }

            override fun onSingleTapConfirmed(e: MotionEvent): Boolean {
                if (onPlayPauseListener != null) {
                    onPlayPauseListener!!.OnPlayPauseListener()
                }
                return true
            }
        })

        setOnTouchListener { v: View, event: MotionEvent ->
            gestureDetector!!.onTouchEvent(event)
            true
        }
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

        animationSet.addAnimation(AnimUtils.rotateAnimation(0, 0, degrees.toFloat()))
        animationSet.addAnimation(AnimUtils.scaleAnim(100, 2f, 1f, 0))
        animationSet.addAnimation(AnimUtils.alphaAnim(0f, 1f, 100, 0))
        animationSet.addAnimation(AnimUtils.scaleAnim(500, 1f, 1.8f, 300))
        animationSet.addAnimation(AnimUtils.alphaAnim(1f, 0f, 500, 300))
        animationSet.addAnimation(AnimUtils.translationAnim(500, 0f, 0f, 0f, -400f, 300))
        animationSet.setAnimationListener(object : Animation.AnimationListener {
            override fun onAnimationStart(animation: Animation?) {
                TODO("Not yet implemented")
            }

            override fun onAnimationEnd(animation: Animation?) {
                Handler().post {
                    removeView(view)
                }
            }

            override fun onAnimationRepeat(animation: Animation?) {
                TODO("Not yet implemented")
            }
        })
        view.startAnimation(animationSet)
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