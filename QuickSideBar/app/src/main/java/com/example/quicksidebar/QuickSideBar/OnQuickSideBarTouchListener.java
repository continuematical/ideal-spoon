package com.example.quicksidebar.QuickSideBar;

public interface OnQuickSideBarTouchListener {
    void onLetterChanged(String letter, int position, float y);

    void onLetterTouching(boolean touching);
}
