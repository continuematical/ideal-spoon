package com.example.geoquiz;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContract;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.ims.RegistrationManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

@SuppressWarnings("DeprecatedIsStillUsed")
public class MainActivity extends AppCompatActivity {
    private Button mTrueButton;
    private Button mFalseButton;
    private Button mCheatButton;

    private ImageButton mNextButton;
    private ImageButton mPrevButton;
    private TextView mQuestionTextView;

    private final static String Answer_list = "answer_list";

    private Question[] mQuestionBank = new Question[]{
            new Question(R.string.question_africa, false),
            new Question(R.string.question_americas, true),
            new Question(R.string.question_asia, true),
            new Question(R.string.question_ocean, true),
            new Question(R.string.question_mideast, false),
            new Question(R.string.question_australia, true)
    };

    private int mCurrentIndex = 0;
    int correctAnswer = 0;

    private final static String TAG = "MainActivity";
    private final static String KEY_INDEX = "index";

    //判断用户是否偷看过答案
    private final static int Request_code_cheat = 0;
    private boolean mIsCheater[] = new boolean[mQuestionBank.length];
    //判断用户偷看答案的次数
    private int num = 3;

    //创建数组判断用户是否作答
    boolean[] mQuestionAnswered = new boolean[mQuestionBank.length];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "onCreate(Bundle) called");
        setContentView(R.layout.activity_main);

        //初始化用户答题情况的数组
        for (int i = 0; i < mQuestionBank.length; i++) {
            mQuestionAnswered[i] = true;
        }

        if (savedInstanceState != null) {
            mCurrentIndex = savedInstanceState.getInt(KEY_INDEX, 0);
        }

        mQuestionTextView = (TextView) findViewById(R.id.question_next);
        updateQuestion();

        //引用组件
        mTrueButton = (Button) findViewById(R.id.true_button);
        mFalseButton = (Button) findViewById(R.id.false_button);
        //设置监听器
        mTrueButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                checkAnswer(true);
            }
        });
        mFalseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                checkAnswer(false);
            }
        });

        //next按钮
        mNextButton = (ImageButton) findViewById(R.id.next_question);
        mNextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                updateQuestion();
                checkIfAnswered();
            }
        });

        //prev按钮
        mPrevButton = (ImageButton) findViewById(R.id.prev_question);
        mPrevButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mCurrentIndex = (mCurrentIndex - 1) % mQuestionBank.length;
                int question = mQuestionBank[mCurrentIndex].getTestResId();
                mQuestionTextView.setText(question);
            }
        });

        //cheat按钮
        mCheatButton = (Button) findViewById(R.id.cheat_button);
        mCheatButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (num > 0) {
                    //start cheatActivity
                    Boolean answerIsTrue = mQuestionBank[mCurrentIndex].isAnswerTrue();//正确答案
                    Intent intent = CheatActivity.newIntent(MainActivity.this, answerIsTrue);
                    //需要从子activity获取返回信息
                    startActivityForResult(intent, Request_code_cheat);
                } else {
                    mCheatButton.setEnabled(false);
                }
            }
        });
    }

    //日志
    public void onStart() {
        super.onStart();
        Log.d(TAG, "onStart() called");
    }

    public void onResume() {
        super.onResume();
        Log.d(TAG, "onResume() called");
    }

    public void onPause() {
        super.onPause();
        Log.d("TAG", "onPause() called");
    }

    public void onSaveInstanceState(Bundle saveInstanceState) {
        super.onSaveInstanceState(saveInstanceState);
        Log.d(TAG, "onSaveInstanceState");
        saveInstanceState.putInt(KEY_INDEX, mCurrentIndex);
    }

    public void onStop() {
        super.onStop();
        Log.d(TAG, "onStop() called");
    }

    public void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "onDestroy() called");
    }

    //updateQuestion
    public void updateQuestion() {
        mCurrentIndex = (mCurrentIndex + 1) % mQuestionBank.length;
        int question = mQuestionBank[mCurrentIndex].getTestResId();
        mQuestionTextView.setText(question);
    }

    //checkAnswer
    public void checkAnswer(boolean userPressed) {
        //禁止一题多答
        checkIfAnswered();
        //获取问题答案
        boolean answerIsTrue = mQuestionBank[mCurrentIndex].isAnswerTrue();
        int messageResId = 0;
        if (mIsCheater[mCurrentIndex]) {
            Toast.makeText(this, R.string.judgeToast, Toast.LENGTH_SHORT).show();
        } else {
            if (userPressed == answerIsTrue) {
                messageResId = R.string.correct_toast;
                correctAnswer++;
            } else {
                messageResId = R.string.incorrect_toast;
            }
        }
        Toast.makeText(MainActivity.this, messageResId, Toast.LENGTH_SHORT).show();
        mQuestionAnswered[mCurrentIndex] = false;
        checkIfAnswered();
        calculateScore();
    }

    //计算分数
    public void calculateScore() {
        String message = getString(R.string.toast_score, correctAnswer);
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    //检查是否回答
    public void checkIfAnswered() {
        mTrueButton.setEnabled(mQuestionAnswered[mCurrentIndex]);
        mFalseButton.setEnabled(mQuestionAnswered[mCurrentIndex]);
    }

    //检查请求代码和返回代码是否符合预期
    protected void onActivityResult(int reqCode, int resultCode, Intent data) {
        //用户未偷看答案
        super.onActivityResult(reqCode, resultCode, data);
        if (resultCode != Activity.RESULT_OK) {
            return;
        }
        if (reqCode == Request_code_cheat) {
            if (data == null) {
                return;
            }
            mIsCheater[mCurrentIndex] = CheatActivity.wasAnswerShow(data);
            num--;
            Toast.makeText(this, getString(R.string.left, num), Toast.LENGTH_SHORT).show();
        }
    }
}
