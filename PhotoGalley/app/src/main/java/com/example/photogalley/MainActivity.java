package com.example.photogalley;
import androidx.fragment.app.Fragment;

public class MainActivity extends SingleFragmentActivity {
    @Override
    public Fragment createFragment() {
        return PhotoGalleyFragment.newInstance();
    }
}