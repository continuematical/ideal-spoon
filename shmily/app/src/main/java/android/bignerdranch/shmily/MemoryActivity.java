package android.bignerdranch.shmily;
import androidx.fragment.app.Fragment;

public class MemoryActivity extends SingleFragmentActivity {
    private final static String RETURN = "return";

    @Override
    protected Fragment createFragment() {
        return new MemoryFragment();
    }

}
