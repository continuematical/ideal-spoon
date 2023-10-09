package com.example.quicksidebar.QuickSideBar;

import android.content.Context;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.Nullable;

public class QuickSideBarTipsItemView extends View {
    private int mCornerRadius;

    private Path mBackgroundPath = new Path();
    private RectF mBackgroundRect = new RectF();
    private Paint mBackgroundPaint;

    private String mText ="";

    private Paint mTextPaint;
    private int mWidth;
    private int mItemHeight;
    private float mTextSize;
    private int mTextColor;
    private int mBackgroundColor;
    private int mCenterTextStartX;
    private int mCenterTextStartY;


    public QuickSideBarTipsItemView(Context context) {
        super(context);
    }

    public QuickSideBarTipsItemView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    public QuickSideBarTipsItemView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    private void init(Context context, AttributeSet attrs){

    }
}
