package com.example.quicksidebar;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Rect;
import android.graphics.drawable.Drawable;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

public class DividerDecoration extends RecyclerView.ItemDecoration {
    private static final int[] ATTRS = new int[]{
            android.R.attr.listDivider
    };

    public static final int HORIZONTAL_LIST = LinearLayoutManager.HORIZONTAL;
    public static final int VERTICAL_LIST = LinearLayoutManager.VERTICAL;

    private Drawable mDivider;

    public DividerDecoration(Context context) {
        final TypedArray a = context.obtainStyledAttributes(ATTRS);
        mDivider = a.getDrawable(0);
        a.recycle();
    }

    private int getOrientation(RecyclerView parent) {
        LinearLayoutManager layoutManager;
        try {
            layoutManager = (LinearLayoutManager) parent.getLayoutManager();
        } catch (ClassCastException e) {
            throw new IllegalStateException("DividerDecoration", e);
        }
        return layoutManager.getOrientation();
    }

    public void drawVertical(Canvas c, RecyclerView parent) {
        final int left = parent.getPaddingLeft();
        final int right = parent.getWidth() - parent.getPaddingRight();
        final int ParentTop = parent.getPaddingTop();
        final int ParentBottom = parent.getHeight() - parent.getPaddingBottom();
        final int childCount = parent.getChildCount();
        for (int i = 0; i < childCount; i++) {
            final View child = parent.getChildAt(i);
            //父容器属性
            final RecyclerView.LayoutParams params = (RecyclerView.LayoutParams) child.getLayoutParams();
            final int top = Math.max(ParentTop, child.getBottom() + params.bottomMargin);
            final int bottom = Math.min(ParentBottom, top + mDivider.getIntrinsicHeight());

            mDivider.setBounds(left, top, right, bottom);
            mDivider.draw(c);
        }
    }

    public void drawHorizontal(Canvas c, RecyclerView parent) {
        final int top = parent.getPaddingTop();
        final int bottom = parent.getHeight() - parent.getPaddingBottom();
        final int ParentLeft = parent.getPaddingLeft();
        final int ParentRight = parent.getWidth() - parent.getPaddingRight();
        final int childCount = parent.getChildCount();
        for (int i = 0; i < childCount; i++) {
            final View child = parent.getChildAt(i);

            final RecyclerView.LayoutParams layoutParams = (RecyclerView.LayoutParams) parent.getLayoutParams();
            final int left = Math.max(ParentLeft, child.getRight() + layoutParams.rightMargin);
            final int right = Math.min(ParentRight, left + mDivider.getIntrinsicHeight());

            mDivider.setBounds(left, top, right, bottom);
            mDivider.draw(c);
        }
    }

    @Override
    public void onDraw(@NonNull Canvas c, @NonNull RecyclerView parent, @NonNull RecyclerView.State state) {
        super.onDraw(c, parent, state);
    }

    @Override
    public void getItemOffsets(@NonNull Rect outRect, @NonNull View view, @NonNull RecyclerView parent, @NonNull RecyclerView.State state) {
        super.getItemOffsets(outRect, view, parent, state);
        if (getOrientation(parent) == HORIZONTAL_LIST) {
            outRect.set(0, 0, mDivider.getIntrinsicHeight(), 0);
        } else {
            outRect.set(0, 0, 0, mDivider.getIntrinsicHeight());
        }
    }
}