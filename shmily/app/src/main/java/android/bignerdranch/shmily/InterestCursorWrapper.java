package android.bignerdranch.shmily;

import android.database.Cursor;
import android.database.CursorWrapper;
import android.bignerdranch.shmily.MemoryDbSchema.InterestTable;
import android.net.Uri;

import java.util.UUID;

public class InterestCursorWrapper extends CursorWrapper {

    public InterestCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public Interest getInterest() {
        String uuidString = getString(getColumnIndex(InterestTable.cols.UUID));
        String title = getString(getColumnIndex(InterestTable.cols.TITLE));
        String text = getString(getColumnIndex(InterestTable.cols.TEXT));
        Uri uri = Uri.parse(getString(getColumnIndex(InterestTable.cols.URI)));

        Interest interest = new Interest(UUID.fromString(uuidString));

        interest.setTitle(title);
        interest.setText(text);
        interest.setUri(uri);

        return interest;
    }
}
