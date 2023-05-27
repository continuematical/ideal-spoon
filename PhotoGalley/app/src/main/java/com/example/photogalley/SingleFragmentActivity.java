package com.example.photogalley;

import android.os.Bundle;
import android.os.PersistableBundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

public abstract class SingleFragmentActivity extends AppCompatActivity {
    public abstract Fragment createFragment();

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState, @Nullable PersistableBundle persistentState) {
        super.onCreate(savedInstanceState, persistentState);
        FragmentManager manager = getSupportFragmentManager();
        Fragment f = manager.findFragmentById(R.id.fragment_container);
        if (f == null) {
            f = createFragment();
            manager.beginTransaction().add(R.id.fragment_container, f).commit();
        }
    }
}
