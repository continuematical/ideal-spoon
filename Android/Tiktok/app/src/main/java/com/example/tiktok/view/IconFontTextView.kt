package com.example.tiktok.view

import android.content.Context
import android.graphics.Typeface
import android.util.AttributeSet
import androidx.appcompat.widget.AppCompatTextView

/**
 * 用于加载IconFont的TextView
 */
class IconFontTextView : AppCompatTextView {
    constructor(context: Context) : super(context) {}
    constructor(context: Context, attributeSet: AttributeSet) : super(context, attributeSet) {}


    companion object {
        private var typeface: Typeface? = null
    }

    init {
        typeface = Typeface.createFromAsset(context.assets, "iconfont.ttf")
        typeface = typeface
    }
}