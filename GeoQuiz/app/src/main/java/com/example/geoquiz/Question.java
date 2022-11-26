package com.example.geoquiz;

public class Question {
    private int mTestResId;
    private boolean mAnswerTrue;
    private boolean isAnswered;

    public Question(int textResId,boolean answerTrue){
        mTestResId=textResId;
        mAnswerTrue=answerTrue;
    }

    public boolean isAnswered(){
        return isAnswered;
    }

    public int getTestResId() {
        return mTestResId;
    }

    public void setTestResId(int testResId) {
        mTestResId = testResId;
    }

    public boolean isAnswerTrue() {
        return mAnswerTrue;
    }

    public void setAnswerTrue(boolean answerTrue) {
        mAnswerTrue = answerTrue;
    }
}
