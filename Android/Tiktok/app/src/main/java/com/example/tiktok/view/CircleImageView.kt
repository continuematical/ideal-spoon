package com.example.tiktok.view

import android.content.Context
import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Matrix
import android.graphics.Paint
import android.graphics.PorterDuff
import android.graphics.PorterDuffXfermode
import android.graphics.RectF
import android.graphics.drawable.BitmapDrawable
import android.graphics.drawable.Drawable
import android.util.AttributeSet
import android.view.MotionEvent
import androidx.appcompat.widget.AppCompatImageView
import com.example.tiktok.R
import java.lang.IllegalArgumentException

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
        init(context, null)
    }

    constructor(context: Context, attrs: AttributeSet) : super(context, attrs) {
        init(context, attrs)
    }

    constructor(context: Context, attrs: AttributeSet, defStyleAttr: Int) : super(
        context,
        attrs,
        defStyleAttr
    ) {
        init(context, attrs)
    }

    private fun init(context: Context, attrs: AttributeSet?) {
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
        val drawable = drawable ?: return
        if (getWidth() == 0 || getHeight() == 0) return

        val bitmap = getBitmapFromDrawable(drawable)
        if (canvas != null) {
            if (bitmap != null) {
                drawDrawable(canvas, bitmap)
            }
        }

        if (isClickable) canvas?.let { drawPress(it) }

        if (canvas != null) {
            drawBorder(canvas)
        }
    }

    /**
     * 绘制
     */
    private fun drawDrawable(canvas: Canvas, bitmap: Bitmap) {
        var bitmap = bitmap
        var paint = Paint()
        //Paint参数
        paint.color = -0x1
        paint.isAntiAlias = true
        var overmodest = PorterDuffXfermode(PorterDuff.Mode.SRC_IN)
        //执行restore函数的时候回收所有东西
        val saveFlags = Canvas.ALL_SAVE_FLAG
        canvas.saveLayer(0f, 0f, width, height, null, saveFlags)
        if (shapeType == 1) {
            canvas.drawCircle(
                (width / 2),
                (height / 2),
                (width / 2 - 1),
                paint
            )
        } else if (shapeType == 2) {
            //绘制圆角矩形
            canvas.drawRoundRect(
                RectF(
                    1f,
                    1f,
                    (getWidth() - 1).toFloat(),
                    (getHeight() - 1).toFloat()
                ), (radius + 1).toFloat(), (radius + 1).toFloat(), paint
            )
        }

        paint.xfermode = overmodest
        val scaleWidth = getWidth().toFloat() / bitmap!!.width
        val scaleHeight = getHeight().toFloat() / bitmap!!.height
        val matrix = Matrix()
        matrix.postScale(scaleWidth, scaleHeight)

        //bitmap scale
        bitmap = Bitmap.createBitmap(bitmap, 0, 0, bitmap.width, bitmap.height, matrix, true)
        canvas.drawBitmap(bitmap, 0f, 0f, paint)
        canvas.restore()
    }

    /**
     * Drawable转化为Bitmap
     */
    private fun getBitmapFromDrawable(drawable: Drawable?): Bitmap? {
        if (drawable == null) return null
        if (drawable is BitmapDrawable) return drawable.bitmap
        //获取高宽
        var bitmap: Bitmap?
        val width = drawable.intrinsicWidth.coerceAtLeast(2)
        val height = drawable.intrinsicHeight.coerceAtLeast(2)
        try {
            //建立对应Bitmap
            bitmap = Bitmap.createBitmap(width, height, BITMAP_CONFIG)
            //建立对应Bitmap的画布
            val canvas = Canvas(bitmap)
            drawable.setBounds(0, 0, canvas.width, canvas.height)
            //将Drawable绘制到Bitmap上
            drawable.draw(canvas)
        } catch (e: IllegalArgumentException) {
            e.printStackTrace()
            bitmap = null
        }

        return bitmap
    }

    companion object {
        private val BITMAP_CONFIG = Bitmap.Config.ARGB_8888
        private const val COLOR_DRAWABLE_DIMENSION = 1
    }

    /**
     * 按压的效果
     */

    private fun drawPress(canvas: Canvas) {
        if (shapeType == 1) {
            canvas.drawCircle(
                (width / 2),
                (height / 2),
                (width / 2 - 1),
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

    /**
     * 绘制边界
     */
    private fun drawBorder(canvas: Canvas) {
        if (borderWidth > 0) {
            val paint = Paint()
            //设置Paint
            paint.strokeWidth = borderWidth.toFloat()
            paint.style = Paint.Style.STROKE
            paint.color = borderColor
            paint.isAntiAlias = true

            if (shapeType == 1) {
                canvas.drawCircle(
                    (width / 2).toFloat(),
                    (height / 2).toFloat(),
                    (width - borderWidth) / 2.toFloat(),
                    paint
                )
            } else if (shapeType == 2) {
                canvas.drawRoundRect(
                    RectF(
                        (borderWidth / 2).toFloat(),
                        (borderWidth / 2).toFloat(),
                        (getWidth() - borderWidth / 2).toFloat(),
                        (getHeight() - borderWidth / 2).toFloat()
                    ),
                    radius.toFloat(),
                    radius.toFloat(),
                    paint
                )
            }
        }
    }


    override fun onTouchEvent(event: MotionEvent?): Boolean {
        when (event?.action) {
            MotionEvent.ACTION_DOWN -> {
                pressPaint!!.alpha = pressAlpha
                invalidate()
            }

            MotionEvent.ACTION_UP -> {
                pressPaint!!.alpha = 0
                invalidate()
            }

            MotionEvent.ACTION_MOVE -> {

            }

            else -> {
                pressPaint!!.alpha = 0
                invalidate()
            }
        }
        return super.onTouchEvent(event)
    }

    override fun onSizeChanged(w: Int, h: Int, oldw: Int, oldh: Int) {
        super.onSizeChanged(w, h, oldw, oldh)
        width = w.toFloat()
        height = h.toFloat()
    }

    /**
     * set border color
     */
    fun setBorderColor(borderColor: Int) {
        this.borderColor = borderColor
        invalidate()
    }

    /**
     * set border width
     */
    fun setBorderWidth(borderWidth: Float) {
        this.borderWidth = borderColor
    }

    /**
     * set press alpha
     */
    fun setPressAlpha(pressAlpha: Float) {
        this.pressAlpha = pressColor
    }

    /**
     * set press color
     */
    fun setPressColor(pressColor: Int) {
        this.pressColor = pressColor
    }

    /**
     * set radius
     */
    fun setRadius(radius: Int) {
        this.radius = radius
        invalidate()
    }

    /**
     * set shape,1 is circle, 2 is rectangle
     */
    fun setShapeType(shapeType: Int) {
        this.shapeType = shapeType
        invalidate()
    }
}