package android.bignerdranch.shmily;

import android.graphics.drawable.Drawable;

import java.util.UUID;

public class Envelope {
    private String text;
    private String date;
    private Drawable mDrawable;
    private UUID mUUID;

    public Envelope() {
        this(UUID.randomUUID());
    }

    public Envelope(UUID uuid) {
        mUUID = uuid;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public Drawable getDrawable() {
        return mDrawable;
    }

    public void setDrawable(Drawable drawable) {
        mDrawable = drawable;
    }
}
