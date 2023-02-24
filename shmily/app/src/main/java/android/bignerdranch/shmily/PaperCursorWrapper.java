package android.bignerdranch.shmily;

import android.database.Cursor;
import android.database.CursorWrapper;
import android.bignerdranch.shmily.MemoryDbSchema.PaperTable;

public class PaperCursorWrapper extends CursorWrapper {

    public PaperCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public Paper getPaper(){
        String date=getString(getColumnIndex(PaperTable.cols.DATE));
        String text=getString(getColumnIndex(PaperTable.cols.TEXT));
        int color=getInt(getColumnIndex(PaperTable.cols.COLOR));

        Paper paper=new Paper();
        paper.setDate(date);
        paper.setText(text);
        paper.setColor(color);

        return paper;
    }
}
