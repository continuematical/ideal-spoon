package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

public class WritePaperActivity extends AppCompatActivity implements View.OnClickListener{
    private EditText mText;
    private EditText mDate;
    private TextView completed;
    private TextView MyPaperStorage;
    private ImageButton preButton;

    private Paper mPaper;

    int flag = 0;
    private ImageButton greenButton;
    private ImageButton pinkButton;
    private ImageButton blueButton;
    private ImageButton yellowButton;
    private ImageButton lightPurpleButton;
    private ImageButton redButton;
    private ImageButton lightGreenButton;
    private ImageButton purpleButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_write_paper);

        mPaper = new Paper();

        greenButton = (ImageButton) findViewById(R.id.green_button);
        pinkButton=(ImageButton)findViewById(R.id.pink_button);
        blueButton = (ImageButton) findViewById(R.id.blue_button);
        yellowButton = (ImageButton) findViewById(R.id.yellow_button);
        lightPurpleButton=(ImageButton)findViewById(R.id.light_purple_button);
        redButton = (ImageButton) findViewById(R.id.red_button);
        lightGreenButton = (ImageButton) findViewById(R.id.light_green_button);
        purpleButton=(ImageButton)findViewById(R.id.purple_button);

        preButton=(ImageButton) findViewById(R.id.pre_button);
        mText = (EditText) findViewById(R.id.write_down);
        mDate = (EditText) findViewById(R.id.write_date);
        completed = (TextView) findViewById(R.id.completed);
        MyPaperStorage = (TextView) findViewById(R.id.my_paper_storage);

        pressColorButton();

        mText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                mPaper.setText(charSequence.toString());
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        mDate.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                mPaper.setDate(charSequence.toString());
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        preButton.setOnClickListener(this);
        completed.setOnClickListener(this);
        MyPaperStorage.setOnClickListener(this);
    }

    private boolean JudgementBlank() {
        if (mPaper.getText() == null) {
            Toast.makeText(this, R.string.please_input_text, Toast.LENGTH_SHORT).show();
            return false;
        }
        if (flag == 0) {
            Toast.makeText(this, R.string.please_choose_color, Toast.LENGTH_SHORT).show();
            return false;
        }
        if (mPaper.getDate() == null) {
            Toast.makeText(this,R.string.please_input_date,Toast.LENGTH_SHORT).show();
            return false;
        }
        return true;
    }

    @Override
    public void onClick(View view) {
        switch(view.getId()){
            case R.id.pre_button:
                Intent returnPaper=new Intent(WritePaperActivity.this,MyPaperStorageActivity.class);
                startActivity(returnPaper);
                break;
            case R.id.completed:
                if(JudgementBlank()) {
                    PaperLab.get(WritePaperActivity.this).addPaper(mPaper);
                    Toast.makeText(WritePaperActivity.this, R.string.The_paper_has_been_in_the_storage, Toast.LENGTH_SHORT).show();
                }
                break;
            case R.id.my_paper_storage:
                Intent intent=new Intent(WritePaperActivity.this,LookAtTheActivity.class);
                startActivity(intent);
                break;
        }
    }

    private class onClick implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.green_button:
                    changeEditColor(R.color.green);
                    break;
                case R.id.blue_button:
                    changeEditColor(R.color.blue);
                    break;
                case R.id.yellow_button:
                    changeEditColor(R.color.yellow);
                    break;
                case R.id.pink_button:
                    changeEditColor(R.color.pink);
                    break;
                case R.id.light_green_button:
                    changeEditColor(R.color.light_green);
                    break;
                case R.id.red_button:
                    changeEditColor(R.color.red);
                    break;
                case R.id.light_purple_button:
                    changeEditColor(R.color.light_purple);
                    break;
                default:
                    changeEditColor(R.color.purple);
                    break;
            }

        }
    }

    public void pressColorButton() {
        onClick onClick = new onClick();

        lightGreenButton.setOnClickListener(onClick);
        lightPurpleButton.setOnClickListener(onClick);
        purpleButton.setOnClickListener(onClick);
        blueButton.setOnClickListener(onClick);
        yellowButton.setOnClickListener(onClick);
        redButton.setOnClickListener(onClick);
        pinkButton.setOnClickListener(onClick);
        greenButton.setOnClickListener(onClick);
    }

    public void changeEditColor(int color) {
        flag = 1;
        mText.setBackgroundColor(ContextCompat.getColor(this,color));
        mPaper.setColor(color);
    }
}