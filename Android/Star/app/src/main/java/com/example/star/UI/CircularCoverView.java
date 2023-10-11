package com.example.star.UI;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.ColorInt;
import androidx.annotation.Nullable;

import com.example.star.R;

public class CircularCoverView extends View {
    private int leftTopRadius = 30;
    private int leftBottomRadius = 30;
    private int rightTopRadius = 30;
    private int rightBottomRadius = 30;
    private int border = 0;
    private int coverColor = 0xffeaeaea;

    public CircularCoverView(Context context) {
        this(context, null, 0);
    }

    public CircularCoverView(Context context, @Nullable AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public CircularCoverView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);

        //提取特性
        TypedArray typedArray = context.obtainStyledAttributes(attrs, R.styleable.CircularCoverView);
        leftBottomRadius = typedArray.getDimensionPixelSize(R.styleable.CircularCoverView_left_bottom_radius, leftBottomRadius);
        leftTopRadius = typedArray.getDimensionPixelSize(R.styleable.CircularCoverView_left_top_radius, leftTopRadius);
        rightBottomRadius = typedArray.getDimensionPixelSize(R.styleable.CircularCoverView_right_bottom_radius, rightBottomRadius);
        leftTopRadius = typedArray.getDimensionPixelSize(R.styleable.CircularCoverView_left_top_radius, leftTopRadius);
    }

    public void setCoverColor(@ColorInt int coverColor) {
        this.coverColor = coverColor;
    }

    public void setRadians(int leftTopRadians, int rightTopRadians, int leftBottomRadians, int rightBottomRadians, int border) {
        this.leftTopRadius = leftTopRadians;
        this.rightTopRadius = rightTopRadians;
        this.leftBottomRadius = leftBottomRadians;
        this.rightBottomRadius = rightBottomRadians;
        this.border = border;
    }

    private Bitmap drawSector(int w, int h) {
        //width height config
        Bitmap bm = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        Canvas c = new Canvas(bm);
        Paint p = new Paint(Paint.ANTI_ALIAS_FLAG);//抗锯齿
        p.setColor(0xFFFFCC44);

        c.drawArc(new RectF(border, border, leftBottomRadius * 2 + border, leftTopRadius * 2 + border), 180, 90, true, p);
        c.drawArc(new RectF(border, getHeight() - leftBottomRadius * 2 - border, leftBottomRadius * 2 + border, getHeight() - border), 90, 90, true, p);
        c.drawArc(new RectF(getWidth() - rightTopRadius * 2 - border, border, getWidth() - border, rightTopRadius * 2 + border), 270, 90, true, p);
        c.drawArc(new RectF(getWidth() - rightBottomRadius * 2 - border, getHeight() - rightBottomRadius * 2 - border, getWidth() - border, getHeight() - border), 0, 90, true, p);
        return bm;
    }

    private Bitmap drawRect(int w, int h) {
        Bitmap bm = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        Canvas c = new Canvas(bm);
        Paint p = new Paint(Paint.ANTI_ALIAS_FLAG);
        p.setColor(coverColor);

        c.drawRect(new RectF(border, border, leftTopRadius + border, leftTopRadius + border), p);
        c.drawRect(new RectF(border, getHeight() - leftBottomRadius - border, leftBottomRadius + border, getHeight() - border), p);
        c.drawRect(new RectF(getWidth() - rightTopRadius - border, border, getWidth() - border, rightTopRadius + border), p);
        c.drawRect(new RectF(getWidth() - rightBottomRadius - border, getHeight() - rightBottomRadius - border, getWidth() - border, getHeight() - border), p);

        c.drawRect(new RectF(0, 0, getWidth(), border), p);
        c.drawRect(new RectF(0, 0, border, getHeight()), p);
        c.drawRect(new RectF(getWidth() - border, 0, getWidth(), getHeight()), p);
        c.drawRect(new RectF(0, getHeight() - border, getWidth(), getHeight()), p);
        return bm;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        try {
            Paint paint = new Paint();
            paint.setFilterBitmap(false);
            paint.setStyle(Paint.Style.FILL);//填充模式

            int sc = canvas.saveLayer(0, 0, getWidth(), getHeight(), null);
            canvas.drawBitmap(drawSector(getWidth(), getHeight()), 0, 0, paint);
            paint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC_OUT));
            canvas.drawBitmap(drawRect(getWidth(), getHeight()), 0, 0, paint);
            //重新设置
            paint.setXfermode(null);
            canvas.restoreToCount(sc);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
