package android.bignerdranch.shmily;

import androidx.fragment.app.Fragment;

public class PaperListActivity extends SingleFragmentActivity{

    @Override
    protected Fragment createFragment() {
        return new PaperListFragment();
    }
}
