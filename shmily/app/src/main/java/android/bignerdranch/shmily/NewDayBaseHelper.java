package android.bignerdranch.shmily;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class NewDayBaseHelper extends SQLiteOpenHelper {

    private static final String name = "NewDayBase_db";
    private static final int version = 1;

    public NewDayBaseHelper(Context context) {
        super(context, name, null, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table " + MemoryDbSchema.NewDayTable.DAY_NAME + "(" + " id integer primary key autoincrement, " +
                MemoryDbSchema.NewDayTable.cols.UUID + "," +
                MemoryDbSchema.NewDayTable.cols.NAME + "," +
                MemoryDbSchema.NewDayTable.cols.DATE + "," +
                MemoryDbSchema.NewDayTable.cols.isReminder + "," +
                MemoryDbSchema.NewDayTable.cols.isTop + ")");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }

}
