package com.example.geoquiz;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button mTrueButton;
    private Button mFalseButton;

    private ImageButton mNextButton;
    private ImageButton mPrevButton;
    private TextView mQuestionTextView;

    private Question[] mQuestionBank = new Question[]{
            new Question(R.string.question_africa, false),
            new Question(R.string.question_americas, true),
            new Question(R.string.question_asia, true),
            new Question(R.string.question_ocean, true),
            new Question(R.string.question_mideast, false),
            new Question(R.string.question_australia, true)
    };

    private int mCurrentIndex = 0;
    int correctAnswer=0;

    private final static String TAG ="MainActivity";
    private final static String KEY_INDEX="index";

    //创建数组判断用户是否作答
    Boolean[] QuestionAnswered=new Boolean[mQuestionBank.length];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG,"onCreate(Bundle) called");
        setContentView(R.layout.activity_main);

        if(savedInstanceState!=null){
            mCurrentIndex=savedInstanceState.getInt(KEY_INDEX,0);
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
                mCurrentIndex = (mCurrentIndex + 1) % mQuestionBank.length;
                updateQuestion();
            }
        });

        //prev按钮
        mPrevButton = (ImageButton)  findViewById(R.id.prev_question);
        mPrevButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mCurrentIndex = (mCurrentIndex - 1) % mQuestionBank.length;
                updateQuestion();
            }
        });
    }

    //日志
    public void onStart() {
        super.onStart();
        Log.d(TAG, "onStart() called");
    }

    public void onResume(){
        super.onResume();
        Log.d(TAG,"onResume() called");
    }

    public void onPause(){
        super.onPause();
        Log.d("TAG","onPause() called");
    }

    public void onSaveInstanceState(Bundle saveInstanceState){
        super.onSaveInstanceState(saveInstanceState);
        Log.d(TAG,"onSaveInstanceState");
        saveInstanceState.putInt(KEY_INDEX,mCurrentIndex);
    }

    public void onStop(){
        super.onStop();
        Log.d(TAG, "onStop() called");
    }

    public void onDestroy(){
        super.onDestroy();
        Log.d(TAG,"onDestroy() called");
    }

    //updateQuestion
    public void updateQuestion() {
        //Log.d(TAG,"Updating question next",new Exception());
        int question = mQuestionBank[mCurrentIndex].getTestResId();
        mQuestionTextView.setText(question);
    }

    //checkAnswer
    public void checkAnswer(boolean userPressed) {
        boolean answerIsTrue = mQuestionBank[mCurrentIndex].isAnswerTrue();
        int messageResId = 0;
        if (userPressed == answerIsTrue) {
            messageResId = R.string.correct_toast;
            correctAnswer++;
        } else {
            messageResId = R.string.incorrect_toast;
        }
        Toast.makeText(MainActivity.this, messageResId, Toast.LENGTH_SHORT).show();
        checkIfAnswered();
        calculateScore();
    }

    //计算分数
    public void calculateScore(){
        String message=getString(R.string.toast_score,correctAnswer);
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    public void checkIfAnswered(){
        QuestionAnswered[mCurrentIndex]=mQuestionBank[mCurrentIndex].isAnswered();
        if(QuestionAnswered[mCurrentIndex]){
            mTrueButton.setEnabled(false);
            mFalseButton.setEnabled(false);
        }else{
            mTrueButton.setEnabled(true);
            mFalseButton.setEnabled(true);
        }
    }
}
