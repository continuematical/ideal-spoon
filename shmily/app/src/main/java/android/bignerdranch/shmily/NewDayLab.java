package android.bignerdranch.shmily;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.bignerdranch.shmily.MemoryDbSchema.NewDayTable;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class NewDayLab {
    private static NewDayLab sNewDayLab;
    private SQLiteDatabase mSQLiteDatabase;
    private Context mContext;

    public NewDayLab(Context context) {
        mContext = context.getApplicationContext();
        mSQLiteDatabase = new NewDayBaseHelper(context).getWritableDatabase();
    }

    public static NewDayLab get(Context context) {
        if (sNewDayLab == null) {
            sNewDayLab = new NewDayLab(context);
        }
        return sNewDayLab;
    }

    public void addNewDay(NewDay newDay) {
        ContentValues contentValues = getContentValues(newDay);
        mSQLiteDatabase.insert(NewDayTable.DAY_NAME, null, contentValues);
    }

    public ContentValues getContentValues(NewDay newDay) {
        ContentValues contentValues = new ContentValues();
        contentValues.put(NewDayTable.cols.NAME, newDay.getName());
        contentValues.put(NewDayTable.cols.DATE, newDay.getDate().getTime());
        contentValues.put(NewDayTable.cols.isReminder, newDay.getReminder());
        contentValues.put(NewDayTable.cols.isTop, newDay.getTop());
        return contentValues;
    }

    public List<NewDay> getNewDays() {
        List list = new ArrayList();
        NewDayCursorWrapper wrapper = queryNewDay(null, null);
        wrapper.moveToFirst();
        try {
            while (!wrapper.isAfterLast()) {
                list.add(wrapper.getNewDay());
                wrapper.moveToNext();
            }
        } finally {
            wrapper.close();
        }
        return list;
    }

    public NewDayCursorWrapper queryNewDay(String where, String[] whereArg) {
        Cursor cursor = mSQLiteDatabase.query(NewDayTable.DAY_NAME, null, where, whereArg, null, null, null);
        return new NewDayCursorWrapper(cursor);
    }

}
