package android.bignerdranch.shmily;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.FragmentManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

public class DrawPaperActivity extends AppCompatActivity {
    private ImageView drawPaper;
    private ImageButton preButton;
    private TextView myPaperStore;
    private List<Paper> mPapers;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_draw_paper);
        drawPaper = findViewById(R.id.draw_paper);
        preButton = findViewById(R.id.pre_button);
        myPaperStore = findViewById(R.id.my_paper_storage);
        mPapers = PaperLab.get(DrawPaperActivity.this).getPapers();
        setOnclick();
    }

    public void setOnclick() {
        onClick onClick = new onClick();
        drawPaper.setOnClickListener(onClick);
        preButton.setOnClickListener(onClick);
        myPaperStore.setOnClickListener(onClick);
    }

    private class onClick implements View.OnClickListener {
        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.draw_paper:
                    if (mPapers.size() != 0) {
                        DrawPaperDialogFragment.Builder builder=new DrawPaperDialogFragment.Builder(DrawPaperActivity.this,mPapers);
                        builder.create().show();
                    }else{
                        Toast.makeText(DrawPaperActivity.this, "储蓄罐没有纸条", Toast.LENGTH_SHORT).show();
                    }
                    break;
                case R.id.pre_button:
                    Intent returnIntent = new Intent(DrawPaperActivity.this, MyPaperStorageActivity.class);
                    startActivity(returnIntent);
                    break;
                default:
                    Intent myPaperStoreIntent = new Intent(DrawPaperActivity.this, PaperListActivity.class);
                    startActivity(myPaperStoreIntent);
                    break;
            }
        }
    }
}