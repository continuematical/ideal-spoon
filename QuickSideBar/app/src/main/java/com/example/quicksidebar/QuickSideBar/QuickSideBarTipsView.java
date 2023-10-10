package com.example.quicksidebar.QuickSideBar;

import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.widget.RelativeLayout;

public class QuickSideBarTipsView extends RelativeLayout {

    private QuickSideBarTipsItemView itemView;

    public QuickSideBarTipsView(Context context) {
        this(context, null);
    }

    public QuickSideBarTipsView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public QuickSideBarTipsView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context, attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        itemView = new QuickSideBarTipsItemView(context, attrs);
        LayoutParams layoutParams = new LayoutParams(LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        addView(itemView, layoutParams);
    }

    public void setText(String text, int position, float y) {
        itemView.setText(text);
        LayoutParams layoutParams = (LayoutParams) itemView.getLayoutParams();
        layoutParams.topMargin = (int) (y - getWidth() / 2.8);
        itemView.setLayoutParams(layoutParams);
    }
}
