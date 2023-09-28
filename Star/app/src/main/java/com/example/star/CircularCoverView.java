package com.example.star;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.ColorInt;
import androidx.annotation.Nullable;

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
        Bitmap bm = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        Canvas c = new Canvas(bm);
        Paint p = new Paint(Paint.ANTI_ALIAS_FLAG);
        return bm;
    }
}
