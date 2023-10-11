package com.example.criminalintent;

import java.util.Date;
import java.util.UUID;

public class Crime {
    private UUID mId;
    private String mTitle;
    private Date mDate;
    private boolean mSolved;
    private boolean mRequiredPolice;
    private String mSuspect;
    private String mPhone;

    public String getPhone() {
        return mPhone;
    }

    public void setPhone(String phone) {
        mPhone = phone;
    }

    public String getSuspect() {
        return mSuspect;
    }

    public void setSuspect(String suspect) {
        mSuspect = suspect;
    }

    public Crime() {
        this(UUID.randomUUID());
        //mId=UUID.randomUUID();产生唯一ID
        //mDate=new Date();作为crime的默认发生时间
    }

    public Crime(UUID uuid) {
        mId = uuid;
        mDate = new Date();
    }

    public UUID getId() {
        return mId;
    }

    public String getTitle() {
        return mTitle;
    }

    public void setTitle(String Title) {
        mTitle = Title;
    }

    public Date getDate() {
        return mDate;
    }

    public void setDate(Date date) {
        mDate = date;
    }

    public boolean isSolved() {
        return mSolved;
    }

    public void setSolved(boolean solved) {
        mSolved = solved;
    }

    public boolean isRequiredPolice() {
        return mRequiredPolice;
    }

    public void setRequiredPolice(boolean requiredPolice) {
        mRequiredPolice = requiredPolice;
    }

    //添加文件名获取方式
    public String getPhotoFileName() {
        return "IMG_" + getId().toString() + ".jpg";
    }
}
