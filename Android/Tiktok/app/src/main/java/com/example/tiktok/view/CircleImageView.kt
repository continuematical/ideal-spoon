package com.example.tiktok.view

import android.content.Context
import android.graphics.Canvas
import android.graphics.Paint
import android.graphics.RectF
import android.util.AttributeSet
import androidx.appcompat.widget.AppCompatImageView
import com.example.tiktok.R

class CircleImageView : AppCompatImageView {

    private var pressPaint: Paint? = null
    private var width: Float = 0f
    private var height: Float = 0f

    private var borderColor = 0
    private var borderWidth = 0
    private var pressAlpha = 0
    private var pressColor = 0
    private var radius = 0
    private var shapeType = 0

    constructor(context: Context) : super(context) {

    }

    constructor(context: Context, attrs: AttributeSet) : super(context, attrs) {

    }

    constructor(context: Context, attrs: AttributeSet, defStyleAttr: Int) : super(
        context,
        attrs,
        defStyleAttr
    ) {

    }

    private fun init(context: Context, attrs: AttributeSet) {
        //初始化
        borderColor = -0x22000001
        borderWidth = 0
        pressAlpha = 0x42
        pressColor = 0x42000000
        radius = 16
        shapeType = 0

        //属性设置
        if (attrs != null) {
            val array = context.obtainStyledAttributes(attrs, R.styleable.CircleImageView)
            borderColor = array.getColor(R.styleable.CircleImageView_ease_border_color, borderColor)
            borderWidth = array.getInt(R.styleable.CircleImageView_ease_border_width, borderWidth)
            pressColor = array.getColor(R.styleable.CircleImageView_ease_press_color, pressColor)
            pressAlpha = array.getInteger(R.styleable.CircleImageView_ease_press_alpha, pressAlpha)
            radius = array.getDimensionPixelOffset(R.styleable.CircleImageView_ease_radius, radius)
            shapeType = array.getInteger(R.styleable.CircleImageView_ease_shape_type, shapeType)
            array.recycle()
        }

        pressPaint = Paint()
        pressPaint!!.isAntiAlias = true
        pressPaint!!.style = Paint.Style.FILL
        pressPaint!!.color = pressColor
        pressPaint!!.alpha = 0
        pressPaint!!.flags = Paint.ANTI_ALIAS_FLAG
        isDrawingCacheEnabled = true
        setWillNotDraw(false)
    }

    override fun onDraw(canvas: Canvas?) {
        if (shapeType == 0) {
            super.onDraw(canvas)
            return
        }

    }

    /**
     * 按压的效果
     */

    private fun drawPress(canvas: Canvas) {
        if (shapeType == 1) {
            canvas.drawCircle(
                (width / 2).toFloat(),
                (height / 2).toFloat(),
                (width / 2 - 1).toFloat(),
                pressPaint!!
            )
        } else if (shapeType == 2) {
            val rectF = RectF(1f, 1f, (width - 1).toFloat(), (height - 1).toFloat())
            canvas.drawRoundRect(
                rectF,
                (radius + 1).toFloat(),
                (radius + 1).toFloat(),
                pressPaint!!
            )
        }
    }
}