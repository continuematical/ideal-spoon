package android.bignerdranch.shmily;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.Fragment;

public abstract class SingleFragmentActivity extends AppCompatActivity {
    abstract protected Fragment createFragment();

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_container);
        FragmentManager manager=getSupportFragmentManager();
        androidx.fragment.app.Fragment fragment=manager.findFragmentById(R.id.fragment_container);
        if(fragment==null){
            fragment=createFragment();
            manager.beginTransaction().add(R.id.fragment_container,fragment).commit();
        }
    }
}
