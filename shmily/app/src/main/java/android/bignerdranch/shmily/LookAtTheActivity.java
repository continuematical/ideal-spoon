package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class LookAtTheActivity extends AppCompatActivity implements View.OnClickListener{
    private ImageButton preButton;
    private ImageButton driftBottle;
    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.look_at_the_paper);
        preButton=findViewById(R.id.pre_button);
        driftBottle=findViewById(R.id.drift_bottle);

        preButton.setOnClickListener(this);
        driftBottle.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch(view.getId()){
            case R.id.pre_button:
                Intent returnPaper=new Intent(LookAtTheActivity.this,MyPaperStorageActivity.class);
                startActivity(returnPaper);
                break;
            case R.id.drift_bottle:
                Intent driftBottle=new Intent(LookAtTheActivity.this,PaperListActivity.class);
                startActivity(driftBottle);
                break;
        }
    }
}
