package android.bignerdranch.shmily;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.fragment.app.Fragment;

public class WriteEnvelopeActivity extends SingleFragmentActivity{

    @Override
    protected Fragment createFragment() {
        return new WriteEnvelopeFragment();
    }

}
