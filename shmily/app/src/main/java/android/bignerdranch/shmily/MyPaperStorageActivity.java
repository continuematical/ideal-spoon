package android.bignerdranch.shmily;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.text.SpannableString;
import android.text.Spanned;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MyPaperStorageActivity extends AppCompatActivity {
    private TextView mMyStorage;
    private TextView mWritePaper;
    private TextView mDrawPaper;
    private ImageButton mPreButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_paper_storage);

        mWritePaper = (TextView) findViewById(R.id.write_paper);
        mDrawPaper = (TextView) findViewById(R.id.draw_paper);
        mMyStorage = (TextView) findViewById(R.id.my_paper_storage);
        mPreButton=(ImageButton)findViewById(R.id.pre_button);

        mWritePaper.setText(SetTextView("写纸条\n\n把那些被爱的瞬间都记录下来叭"));
        mDrawPaper.setText(SetTextView("抽纸条\n\n难过生气时就看看它"));
        setOnListener();
    }

    private void setOnListener(){
        onClick onClick=new onClick();
        mWritePaper.setOnClickListener(onClick);
        mPreButton.setOnClickListener(onClick);
        mDrawPaper.setOnClickListener(onClick);
        mMyStorage.setOnClickListener(onClick);
    }

    private class onClick implements View.OnClickListener{

        @Override
        public void onClick(View view) {
            Intent intent=null;
            switch(view.getId()){
                case R.id.write_paper:
                    intent=new Intent(MyPaperStorageActivity.this,WritePaperActivity.class);
                    startActivity(intent);
                    break;
                case R.id.draw_paper:
                    Intent drawPaperIntent=new Intent(MyPaperStorageActivity.this,DrawPaperActivity.class);
                    startActivity(drawPaperIntent);
                    break;
                case R.id.pre_button:
                    Intent returnIntent=new Intent(MyPaperStorageActivity.this,MemoryActivity.class);
                    startActivity(returnIntent);
                    break;
                case R.id.my_paper_storage:
                    intent=new Intent(MyPaperStorageActivity.this,LookAtTheActivity.class);
                    startActivity(intent);
                    break;
            }
        }
    }

    public SpannableString SetTextView(String text) {
        SpannableString mSpannableString = new SpannableString(text);
        mSpannableString.setSpan(new AbsoluteSizeSpan(80), 0, 3, SpannableString.SPAN_INCLUSIVE_INCLUSIVE);
        mSpannableString.setSpan(new AbsoluteSizeSpan(50), 4, text.length(), SpannableString.SPAN_INCLUSIVE_INCLUSIVE);
        mSpannableString.setSpan(new ForegroundColorSpan(Color.rgb(0, 0, 0)), 0, text.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
        return mSpannableString;
    }

}