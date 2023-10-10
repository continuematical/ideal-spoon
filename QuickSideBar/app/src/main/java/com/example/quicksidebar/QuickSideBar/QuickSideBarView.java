package com.example.quicksidebar.QuickSideBar;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.Nullable;

import com.example.quicksidebar.R;

import java.util.Arrays;
import java.util.List;

public class QuickSideBarView extends View {

    private OnQuickSideBarTouchListener listener;

    private List<String> mLetters;//侧边栏字母
    private int mChoose = -1;
    private Paint mPaint = new Paint();//画笔
    private float mTextSize;
    private float mTextSizeChoose;//选择字母的大小
    private int mTextColor;
    private int mTextColorChoose;
    private int mWidth;
    private int mHeight;
    private float mItemHeight;
    //侧边栏开始的纵坐标
    private float mItemStartY;

    public QuickSideBarView(Context context) {
        this(context, null);
    }

    public QuickSideBarView(Context context, @Nullable AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public QuickSideBarView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context, attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        mLetters = Arrays.asList(context.getResources().getStringArray(R.array.quickSideBarLetters));
        //获取资源
        mTextColor = context.getResources().getColor(android.R.color.black);
        mTextColor = context.getResources().getColor(android.R.color.black);
        mTextColorChoose = context.getResources().getColor(android.R.color.black);
        mTextSize = context.getResources().getDimensionPixelSize(R.dimen.textSize_QuickSideBar);
        mTextSizeChoose = context.getResources().getDimensionPixelSize(R.dimen.textSize_QuickSideBar_choose);
        mItemHeight = context.getResources().getDimension(R.dimen.height_QuickSideBarItem);
        if (attrs != null) {
            // 获取View属性集合
            TypedArray a = getContext().obtainStyledAttributes(attrs, R.styleable.QuickSideBarView);

            mTextColor = a.getColor(R.styleable.QuickSideBarView_sidebarTextColor, mTextColor);
            mTextColorChoose = a.getColor(R.styleable.QuickSideBarView_sidebarTextColorChoose, mTextColorChoose);
            mTextSize = a.getDimension(R.styleable.QuickSideBarView_sidebarTextSize, mTextSize);
            mTextSizeChoose = a.getDimension(R.styleable.QuickSideBarView_sidebarTextSizeChoose, mTextSizeChoose);
            mItemHeight = a.getDimension(R.styleable.QuickSideBarView_sidebarItemHeight, mItemHeight);

            a.recycle();
        }
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
        mHeight = getMeasuredHeight();
        mWidth = getMeasuredWidth();
        mItemStartY = (mHeight - mLetters.size() * mItemHeight) / 2;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        //绘制 26 个字母
        for (int i = 0; i < 26; i++) {
            mPaint.setColor(mTextColor);
            mPaint.setAntiAlias(true);//抗锯齿
            mPaint.setTextSize(mTextSize);

            if (i == mChoose) {
                mPaint.setColor(mTextColorChoose);
                mPaint.setFakeBoldText(true);
                mPaint.setTypeface(Typeface.DEFAULT_BOLD);
                mPaint.setTextSize(mTextSizeChoose);
            }
        }

        //计算位置
    }

    public OnQuickSideBarTouchListener getListener() {
        return listener;
    }

    public void setListener(OnQuickSideBarTouchListener listener) {
        this.listener = listener;
    }

    @Override
    public boolean dispatchTouchEvent(MotionEvent event) {
        return super.dispatchTouchEvent(event);

    }

    public List<String> getLetters() {
        return mLetters;
    }

    public void setLetters(List<String> mLetters) {
        this.mLetters = mLetters;
        invalidate();
    }
}
