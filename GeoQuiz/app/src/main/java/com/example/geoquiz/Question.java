package com.example.geoquiz;

public class Question {
    private int mTestResId;
    private boolean mAnswerTrue;
    private boolean isAnswered;

    public Question(int textResId, boolean answerTrue) {
        mTestResId = textResId;
        mAnswerTrue = answerTrue;
    }

    //用户是否回答
    public boolean isAnswered() {
        return isAnswered;
    }

    //获取问题id
    public int getTestResId() {
        return mTestResId;
    }

    //设置问题id
    public void setTestResId(int testResId) {
        mTestResId = testResId;
    }

    //问题答案
    public boolean isAnswerTrue() {
        return mAnswerTrue;
    }

    //设置问题答案
    public void setAnswerTrue(boolean answerTrue) {
        mAnswerTrue = answerTrue;
    }

    //设置答题情况
    public void setAnswered(boolean answered) {
        isAnswered = answered;
    }
}
