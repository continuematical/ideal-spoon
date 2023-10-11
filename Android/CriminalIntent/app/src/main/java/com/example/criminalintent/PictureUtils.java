package com.example.criminalintent;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Point;
import android.view.View;

public class PictureUtils {
    public static Bitmap getScaledBitmap(String path, int destWidth, int destHeight) {
        //读取图片的像素
        BitmapFactory.Options options = new BitmapFactory.Options();
        options.inJustDecodeBounds = true;
        //如果设置为true，解码器将返回null(没有位图)，但是输出…字段仍然会被设置，允许调用者查询位图而不必为其像素分配内存。
        BitmapFactory.decodeFile(path, options);

        float srcWidth = options.outWidth;
        float srcHeight = options.outHeight;

        //决定缩略图像素的大小
        int inSampleSize = 1;//与原始图片像素大小一样
        if (srcHeight > destHeight || srcWidth > destWidth) {
            float heightScale = srcHeight / destHeight;
            float widthScale = srcWidth / destWidth;

            inSampleSize = Math.round(heightScale > widthScale ? heightScale : widthScale);
        }

        options = new BitmapFactory.Options();
        options.inSampleSize = inSampleSize;
        return BitmapFactory.decodeFile(path, options);
    }

    //预估方法
    //确认屏幕的尺寸，然后按此缩放图像，这样保证载入的ImageView不会过大
    public static Bitmap getScaledBitmap(String path, Activity activity) {
        Point size = new Point();
        activity.getWindowManager().getDefaultDisplay()
                .getSize(size);
        return getScaledBitmap(path, size.x, size.y);
    }
}
