package android.bignerdranch.dialog;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.DialogFragment;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button dialog;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dialog=findViewById(R.id.dialog);
        dialog.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDialog();
            }
        });
    }

    public void showDialog(){
        ProgressDialog dialog=new ProgressDialog(MainActivity.this);
        dialog.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
        dialog.setIndeterminate(false);
        dialog.setProgress(0);//设置初始进度
        dialog.setMax(100);//设置进度最大值
        dialog.show();
        new Thread(new Runnable() {
            @Override
            public void run() {
                int p=0;
                while(p<100){
                    try{
                        Thread.sleep(100);
                        p++;
                        dialog.setProgress(p);
                    }catch (InterruptedException e){
                        e.printStackTrace();
                    }
                }
                dialog.cancel();//达到最大值取消
            }
        }).start();
    }
}