package android.bignerdranch.shmily;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.bignerdranch.shmily.MemoryDbSchema.InterestTable;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class InterestLab {
    private static InterestLab sInterestLab;
    private static Context mContext;
    private SQLiteDatabase mSQLiteDatabase;

    public InterestLab(Context context) {
        mContext = context;
        mSQLiteDatabase = new InterestBaseHelper(context).getWritableDatabase();
    }

    public List<Interest> getInterests() {
        List<Interest> interests = new ArrayList<>();
        InterestCursorWrapper wrapper = queryInterest(null, null);
        wrapper.moveToFirst();
        try {
            while (!wrapper.isAfterLast()) {
                interests.add(wrapper.getInterest());
                wrapper.moveToNext();
            }
        } finally {
            wrapper.close();
        }
        return interests;
    }

    public Interest getInterest(UUID uuid) {
        InterestCursorWrapper wrapper = queryInterest(InterestTable.cols.UUID + "=?", new String[]{uuid.toString()});
        try {
            if (wrapper.getCount() == 0) {
                return null;
            }
            wrapper.moveToFirst();
            return wrapper.getInterest();
        } finally {
            wrapper.close();
        }
    }

    public InterestCursorWrapper queryInterest(String where, String[] whereArgs) {
        Cursor cursor = mSQLiteDatabase.query(InterestTable.INTEREST_NAME, null, where, whereArgs, null, null, null);
        return new InterestCursorWrapper(cursor);
    }

    public static InterestLab get(Context context) {
        if (sInterestLab == null) {
            sInterestLab = new InterestLab(context);
        }
        return sInterestLab;
    }

    public void addInterest(Interest interest) {
        ContentValues values = getContentValues(interest);
        mSQLiteDatabase.insert(InterestTable.INTEREST_NAME, null, values);
    }

    public ContentValues getContentValues(Interest interest) {
        ContentValues values = new ContentValues();
        values.put(InterestTable.cols.UUID,interest.getUUID().toString());
        values.put(InterestTable.cols.TITLE, interest.getTitle());
        values.put(InterestTable.cols.TEXT, interest.getText());
        values.put(InterestTable.cols.URI, interest.getUri().toString());
        return values;
    }
}
