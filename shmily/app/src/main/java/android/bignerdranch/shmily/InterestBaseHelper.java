package android.bignerdranch.shmily;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.bignerdranch.shmily.MemoryDbSchema.InterestTable;

import androidx.annotation.Nullable;

public class InterestBaseHelper extends SQLiteOpenHelper {
    private final static int VERSION=2;

    public InterestBaseHelper(@Nullable Context context) {
        super(context,InterestTable.INTEREST_NAME,null,VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create table "+InterestTable.INTEREST_NAME+"("+" id integer primary key autoincrement, "+
                InterestTable.cols.UUID+","+
                InterestTable.cols.TITLE+","+
                InterestTable.cols.TEXT+","+
                InterestTable.cols.URI+")");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
}
