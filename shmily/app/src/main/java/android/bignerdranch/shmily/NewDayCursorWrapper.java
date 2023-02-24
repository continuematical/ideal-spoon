package android.bignerdranch.shmily;

import android.database.Cursor;
import android.database.CursorWrapper;
import android.bignerdranch.shmily.MemoryDbSchema.NewDayTable;

import java.util.Date;

public class NewDayCursorWrapper extends CursorWrapper {
    public NewDayCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public NewDay getNewDay() {
        NewDay mNewDay = new NewDay();
        String name = getString(getColumnIndex(NewDayTable.cols.NAME));
        long date = getLong(getColumnIndex(NewDayTable.cols.DATE));
        int isReminder = getInt(getColumnIndex(NewDayTable.cols.isReminder));
        int isTop = getInt(getColumnIndex(NewDayTable.cols.isTop));

        mNewDay.setName(name);
        mNewDay.setDate(new Date(date));
        mNewDay.setReminder(isReminder);
        mNewDay.setTop(isTop);

        return mNewDay;
    }
}
