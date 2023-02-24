package android.bignerdranch.shmily;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.List;

import android.bignerdranch.shmily.MemoryDbSchema.PaperTable;

public class PaperLab {
    private static PaperLab sPaperLab;
    private SQLiteDatabase mSQLiteDatabase;
    private static Context mContext;

    public PaperLab(Context context) {
        mContext = context.getApplicationContext();
        mSQLiteDatabase = new PaperBaseHelper(mContext).getWritableDatabase();
    }

    public void addPaper(Paper paper) {
        ContentValues values = getContentValues(paper);
        mSQLiteDatabase.insert(PaperTable.PAPER_NAME, null, values);
    }

    public void updatePaper(Paper paper){
        String uuidString=paper.getID().toString();
        ContentValues values=getContentValues(paper);
        mSQLiteDatabase.update(PaperTable.PAPER_NAME,values,PaperTable.cols.UUID+"=?",new String[]{uuidString});
    }

    public List<Paper> getPapers() {
        List<Paper> papers = new ArrayList<>();
        PaperCursorWrapper wrapper = queryPapers(null, null);
        wrapper.moveToFirst();
        try {
            while (!wrapper.isAfterLast()) {
                papers.add(wrapper.getPaper());
                wrapper.moveToNext();
            }
        } finally {
            wrapper.close();
        }
        return papers;
    }

    public ContentValues getContentValues(Paper paper) {
        ContentValues values = new ContentValues();
        values.put(PaperTable.cols.DATE, paper.getDate());
        values.put(PaperTable.cols.TEXT, paper.getText());
        values.put(PaperTable.cols.COLOR, paper.getColor());
        return values;
    }

    public PaperCursorWrapper queryPapers(String where, String[] whereArgs) {
        Cursor cursor = mSQLiteDatabase.query(PaperTable.PAPER_NAME, null, where, whereArgs, null, null, null);
        return new PaperCursorWrapper(cursor);
    }

    public static PaperLab get(Context context) {
        if (sPaperLab == null) {
            sPaperLab = new PaperLab(context);
        }
        return sPaperLab;
    }

}
