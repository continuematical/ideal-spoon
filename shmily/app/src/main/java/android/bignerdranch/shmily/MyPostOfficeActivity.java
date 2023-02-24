package android.bignerdranch.shmily;

import androidx.fragment.app.Fragment;

public class MyPostOfficeActivity extends SingleFragmentActivity {

    @Override
    protected Fragment createFragment() {
        return new MyPostOfficeFragment();
    }
}