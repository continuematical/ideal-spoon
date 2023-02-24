package com.example.geoquiz;

import androidx.appcompat.app.AppCompatActivity;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.ViewAnimationUtils;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class CheatActivity extends AppCompatActivity {

    //Extra是一个键值对，需要用包名修饰，避免重名
    private static final String Extra_Answer_Is_True = "com.example.android.GeoQuiz.answer_is_true";
    private static final String Extra_Answer_Shown = "com.example.android.GeoQuiz.answer_shown";

    private boolean mAnswerTrue;
    private TextView mAnswerQuestionView;
    private Button mShowAnswerButton;
    private TextView mVersion;

    public static Intent newIntent(Context packageContext, boolean answerIsTrue) {
        Intent intent = new Intent(packageContext, CheatActivity.class);
        intent.putExtra(Extra_Answer_Is_True, answerIsTrue);
        return intent;
    }

    public static Boolean wasAnswerShow(Intent result) {
        //获取intent中extra的数据
        return result.getBooleanExtra(Extra_Answer_Shown, false);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cheat);

        mAnswerTrue = getIntent().getBooleanExtra(Extra_Answer_Is_True, false);
        //CheatActivity界面下的答案
        mAnswerQuestionView = findViewById(R.id.answer_text_view);
        mShowAnswerButton = (Button) findViewById(R.id.show_answer_question);
        //显示SDK的版本
        mVersion=findViewById(R.id.mVersion);
        mVersion.setText("API level "+Build.VERSION.SDK_INT);
        //展示答案
        mShowAnswerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mAnswerTrue) {
                    mAnswerQuestionView.setText(R.string.true_button);
                } else {
                    mAnswerQuestionView.setText(R.string.false_button);
                }
                setAnswerShownResult(true);

                //检查设备的编译版本
                if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.LOLLIPOP){
                    //设置动画
                    int cx=mShowAnswerButton.getWidth();
                    int cy=mShowAnswerButton.getHeight();
                    float radius=mShowAnswerButton.getWidth();
                    //指定要隐藏的按钮
                    Animator anim= ViewAnimationUtils.createCircularReveal(mShowAnswerButton,cx,cy,radius,0);
                    //设置监听器，确定动画何时结束
                    anim.addListener(new AnimatorListenerAdapter() {
                        @Override
                        public void onAnimationEnd(Animator animation) {
                            super.onAnimationEnd(animation);
                            mShowAnswerButton.setVisibility(View.INVISIBLE);
                        }
                    });

                    anim.start();
                }else{
                    mShowAnswerButton.setVisibility(View.INVISIBLE);
                }
            }
        });
    }

    //返回值
    private void setAnswerShownResult(boolean isAnswerShown) {
        Intent data = new Intent();
        data.putExtra(Extra_Answer_Shown, isAnswerShown);
        setResult(RESULT_OK, data);
    }
}

