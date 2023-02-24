package android.bignerdranch.shmily;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.bignerdranch.shmily.MemoryDbSchema.PaperTable;

public class PaperBaseHelper extends SQLiteOpenHelper {
    private final static int version=1;
    private final static String DATA_NAME="PaperBase_db";

    public PaperBaseHelper(Context context){
        super(context,DATA_NAME,null,version);
    }
    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create table "+PaperTable.PAPER_NAME+"("+" id integer primary key autoincrement, "+
                PaperTable.cols.UUID+","+
                PaperTable.cols.DATE+","+
                PaperTable.cols.TEXT+","+
                PaperTable.cols.COLOR+")");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
}
