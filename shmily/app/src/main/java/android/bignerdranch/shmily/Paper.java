package android.bignerdranch.shmily;

import android.graphics.drawable.Drawable;

import java.util.Date;
import java.util.UUID;

public class Paper {
    private UUID mID;
    private String mText;
    private String mDate;
    private int color;

    public int getColor() {
        return color;
    }

    public void setColor(int color) {
        this.color = color;
    }

    public Paper(){
        this(UUID.randomUUID());
    }

    public Paper(UUID uuid) {
        mID=uuid;
    }

    public String getText() {
        return mText;
    }

    public void setText(String text) {
        mText = text;
    }

    public String getDate() {
        return mDate;
    }

    public void setDate(String date) {
        mDate = date;
    }

    public UUID getID() {
        return mID;
    }
}
