package com.example.tiktok.utils

import android.view.animation.Animation
import android.view.animation.DecelerateInterpolator
import android.view.animation.RotateAnimation
import android.view.animation.ScaleAnimation

object AnimUtils {
    /**
     * 以中心缩放动画
     */

    fun scaleAnim(time: Long, from: Float, to: Float, offsetTime: Long): ScaleAnimation {
        val scaleAnimation = ScaleAnimation(
            from, to, from, to,
            Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f
        )

        scaleAnimation.startOffset = offsetTime
        scaleAnimation.interpolator = DecelerateInterpolator()
        scaleAnimation.duration = time
        return scaleAnimation
    }

    /**
     * 旋转动画
     */

    fun rotateAnimation(time: Long, fromDegrees: Int, toDegrees: Float): RotateAnimation {
        val rotateAnimation = RotateAnimation(
            fromDegrees.toFloat(),
            toDegrees,
            Animation.RELATIVE_TO_SELF,
            0.5f,
            Animation.RELATIVE_TO_SELF,
            0.5f
        )
        rotateAnimation.duration = time
        return rotateAnimation
    }

    /**
     * 移动动画
     */

    fun translationAnim(time: Long, fromX: Float, toX: Float) {

    }
}