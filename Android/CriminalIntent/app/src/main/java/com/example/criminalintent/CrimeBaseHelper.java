package com.example.criminalintent;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.criminalintent.CrimeDbSchema.CrimeTable;

//对数据库进行创建和升级
public class CrimeBaseHelper extends SQLiteOpenHelper {
    private static final int VERSION=1;
    private static final String DateBase_NAME="crimeBase_db";

    public CrimeBaseHelper(Context context){
        //context 数据库名
        //允许我们在查询数据时返回一个Cursor，一般传入null
        //数据库版本,可用于对数据库进行升级操作
        super(context,DateBase_NAME,null,VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create table "+CrimeTable.Name+"("+" id integer primary key autoincrement, "+
                CrimeTable.Cols.UUID+","+
                CrimeTable.Cols.TITLE+","+
                CrimeTable.Cols.DATE+","+
                CrimeTable.Cols.SOLVED+","+
                CrimeTable.Cols.SUSPECT+")"
        );
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
}
