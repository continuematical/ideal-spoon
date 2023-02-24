package android.bignerdranch.shmily;

import android.media.Image;
import android.net.Uri;
import android.opengl.Matrix;

import java.util.UUID;

public class Interest {
    private String title;
    private String text;
    private UUID mUUID;
    private Uri mUri;

    public Uri getUri() {
        return mUri;
    }

    public void setUri(Uri uri) {
        mUri = uri;
    }

    public Interest(){
        this(UUID.randomUUID());
    }

    public Interest(UUID uuid) {
        mUUID=uuid;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public UUID getUUID() {
        return mUUID;
    }

    public void setUUID(UUID UUID) {
        mUUID = UUID;
    }
}
