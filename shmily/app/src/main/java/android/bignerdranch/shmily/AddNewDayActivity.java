package android.bignerdranch.shmily;

import androidx.fragment.app.Fragment;

public class AddNewDayActivity extends SingleFragmentActivity{

    @Override
    protected Fragment createFragment() {
        return new AddNewDayFragment();
    }
}
