package android.bignerdranch.myretrofit;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;


import com.squareup.okhttp.OkHttpClient;
import com.squareup.okhttp.logging.HttpLoggingInterceptor;

import retrofit.Call;
import retrofit.Callback;
import retrofit.GsonConverterFactory;
import retrofit.Response;
import retrofit.Retrofit;

public class MainActivity extends AppCompatActivity {
    private EditText name;
    private EditText email;
    private EditText age;
    private EditText topics;
    private Button CreateAccountButton;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name=findViewById(R.id.input_name);
        email=findViewById(R.id.input_email);
        age=findViewById(R.id.input_age);
        topics=findViewById(R.id.input_topics);
        CreateAccountButton=(Button)findViewById(R.id.create_account_button);

        CreateAccountButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                GithubRepo user=new GithubRepo(
                        name.getText().toString(),
                        email.getText().toString(),
                        Integer.parseInt(age.getText().toString()),
                        topics.getText().toString().split(","));

                sendNetWorkRequest(user);
            }
        });
    }

    public void sendNetWorkRequest(GithubRepo user){
        //create okhttp instance
        OkHttpClient httpClient=new OkHttpClient();
        //日志拦截器
        HttpLoggingInterceptor loggingInterceptor=new HttpLoggingInterceptor();
        loggingInterceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
        //create retrofit instance
        Retrofit retrofit=new Retrofit.Builder().baseUrl("https://www.taobao.com/").addConverterFactory(GsonConverterFactory.create()).client(httpClient).build();
        GithubClient client=retrofit.create(GithubClient.class);
        Call<GithubRepo> call=client.onCreate(user);
        call.enqueue(new Callback<GithubRepo>() {
            @Override
            public void onResponse(Response<GithubRepo> response, Retrofit retrofit) {
                Toast.makeText(getApplicationContext(),"my ID is"+response.body().getID(),Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onFailure(Throwable t) {
                Toast.makeText(getApplicationContext(),"error",Toast.LENGTH_SHORT).show();
            }
        });
    }
}

