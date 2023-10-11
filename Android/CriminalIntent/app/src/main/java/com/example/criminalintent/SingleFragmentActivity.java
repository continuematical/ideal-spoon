package com.example.criminalintent;

import static com.example.criminalintent.R.id.fragment_container;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

public abstract class SingleFragmentActivity extends AppCompatActivity {
    protected abstract Fragment CreateFragment();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fragment);

        //获取fragment组件
        FragmentManager fm = getSupportFragmentManager();//可以支持3.0以下API版本，3.0以上的系统可以直接调用getFragmentManager
        Fragment fragment = fm.findFragmentById(R.id.fragment_container);

        if (fragment == null) {
            fragment=CreateFragment();
            //创建并返回FragmentTransaction实例，执行添加操作，提交该事务
            fm.beginTransaction().add(fragment_container,fragment).commit();
        }
    }
}
