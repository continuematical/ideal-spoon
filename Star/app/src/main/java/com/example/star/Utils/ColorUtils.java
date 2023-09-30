package com.example.star.Utils;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Color;

import java.util.HashMap;
import java.util.Random;

public class ColorUtils {
    private static HashMap<String, Integer> colors = new HashMap<>();

    public static int getColor(Context context, String key) {
        if (colors.get(key) == null) {
            int c = getColorsFromSP(context, key);
            if (c == -1) {
                int color = ColorUtils.randomColor(200, 200, 200);
                colors.put(key, color);
                saveColorInSp(context, key, color);
                return color;
            } else {
                return c;
            }
        } else {
            return colors.get(key);
        }
    }

    private static int getColorsFromSP(Context context, String key) {
        SharedPreferences sp = context.getSharedPreferences("StarDemo", Activity.MODE_PRIVATE);
        return sp.getInt(key, -1);
    }

    private static void saveColorInSp(Context context, String key, int value) {
        SharedPreferences sp = context.getSharedPreferences("StarDemo", Activity.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putInt(key, value);
        editor.commit();
    }

    private static int randomColor() {
        return randomColor(256, 256, 256);
    }

    private static int randomColor(int r, int g, int b) {
        Random random = new Random();
        int _r = random.nextInt(r);
        int _g = random.nextInt(g);
        int _b = random.nextInt(b);
        return Color.rgb(_r, _g, _b);
    }
}
