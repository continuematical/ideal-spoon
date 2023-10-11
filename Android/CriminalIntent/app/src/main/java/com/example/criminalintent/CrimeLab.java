package com.example.criminalintent;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.database.sqlite.SQLiteDatabase;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

//单例模式，随时获取数据
public class CrimeLab {
    private static CrimeLab sCrimeLab;//静态变量命名前缀
    //创建空list保存Crime对象
    //private List<Crime> mCrimes;
    //创建数据库
    private Context mContext;
    private SQLiteDatabase mSQLiteDatabase;

    private CrimeLab(Context context) {
        mContext = context.getApplicationContext();
        mSQLiteDatabase = new CrimeBaseHelper(mContext).getWritableDatabase();
//        for (int i = 0; i < 100; i++) {
//            Crime crime = new Crime();
//            crime.setSolved(i % 2 == 0);
//            crime.setTitle("Crime #" + i);
//            if (i % 2 == 0) {
//                crime.setRequiredPolice(true);
//            } else {
//                crime.setRequiredPolice(false);
//            }
//        }
    }


    public ContentValues getContentValues(Crime crime) {
        ContentValues values = new ContentValues();
        values.put(CrimeDbSchema.CrimeTable.Cols.UUID, crime.getId().toString());
        values.put(CrimeDbSchema.CrimeTable.Cols.TITLE, crime.getTitle());
        values.put(CrimeDbSchema.CrimeTable.Cols.DATE, crime.getDate().getTime());
        values.put(CrimeDbSchema.CrimeTable.Cols.SOLVED, crime.isSolved() ? 1 : 0);
        values.put(CrimeDbSchema.CrimeTable.Cols.SUSPECT, crime.getSuspect());
        return values;
    }

    public void addCrime(Crime c) {
        ContentValues values = getContentValues(c);
        mSQLiteDatabase.insert(CrimeDbSchema.CrimeTable.Name, null, values);
    }

    public void deleteCrime(Crime c) {
        ContentValues values = getContentValues(c);
        mSQLiteDatabase.delete(CrimeDbSchema.CrimeTable.Name, CrimeDbSchema.CrimeTable.Cols.UUID + "=?", new String[]{c.getId().toString()});
    }

    public List<Crime> getCrimes() {
        List<Crime> crimes = new ArrayList<>();
        CrimeCursorWrapper cursorWrapper = queryCrimes(null, null);
        cursorWrapper.moveToFirst();
        try {
            while (!cursorWrapper.isAfterLast()) {
                crimes.add(cursorWrapper.getCrime());
                cursorWrapper.moveToNext();
            }
        } finally {
            cursorWrapper.close();
        }
        return crimes;
    }

    public Crime getCrime(UUID id) {
        CrimeCursorWrapper cursor = queryCrimes(CrimeDbSchema.CrimeTable.Cols.UUID + "=?", new String[]{id.toString()});
        try {
            if (cursor.getCount() == 0) {
                return null;
            }
            cursor.moveToFirst();
            return cursor.getCrime();
        } finally {
            cursor.close();
        }
    }

    public void updateCrime(Crime crime) {
        ContentValues values = getContentValues(crime);
        String uuidString = crime.getId().toString();
        mSQLiteDatabase.update(CrimeDbSchema.CrimeTable.Name, values, CrimeDbSchema.CrimeTable.Cols.UUID + "=?", new String[]{uuidString});
    }

    private CrimeCursorWrapper queryCrimes(String where, String[] whereArgs) {
        //表数据处理工具，封装数据表中的原始字段值
        Cursor cursor = mSQLiteDatabase.query(CrimeDbSchema.CrimeTable.Name, null, where, whereArgs, null, null, null);
        return new CrimeCursorWrapper(cursor);
    }

    public static CrimeLab get(Context context) {
        if (sCrimeLab == null) {
            sCrimeLab = new CrimeLab(context);
        }
        return sCrimeLab;
    }

    public File getPhotoFile(Crime crime) {
        File fileDir = mContext.getFilesDir();//获取/data/data/<包名>/files目录
        return new File(fileDir, crime.getPhotoFileName());//创建文件
    }
}
