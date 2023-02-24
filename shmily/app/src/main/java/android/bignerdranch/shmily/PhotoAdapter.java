package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.Context;

import android.provider.ContactsContract;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;

import com.bumptech.glide.Glide;

import java.io.File;
import java.util.List;

public class PhotoAdapter extends BaseAdapter {
    public List<String> filePath;

    private LayoutInflater mInflater;
    private Context context;

    public PhotoAdapter(Context context, List<String> filePath) {
        this.context = context;
        this.filePath = filePath;
        mInflater = LayoutInflater.from(context);
    }

    @Override
    public int getCount() {
        if (filePath != null) {
            return filePath.size() + 1;
        }
        return 1;
    }

    @Override
    public Object getItem(int position) {
        return filePath.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @SuppressLint("ResourceType")
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        PhotoHolder holder = null;
        if (convertView == null) {
            convertView = mInflater.inflate(R.layout.list_photo_item, parent, false);
            holder = new PhotoHolder(convertView);
            convertView.setTag(holder);
        } else {
            holder = (PhotoHolder) convertView.getTag();
        }
        holder.onBind(position);
        return convertView;
    }

    public void setPhotos(List<String> filePath) {
        this.filePath = filePath;
    }

    private class PhotoHolder {
        private ImageView mImageView;

        public PhotoHolder(View view) {
            mImageView = view.findViewById(R.id.image);
        }

        public void onBind(int position) {
            if (position != 0) {
                File file = new File(filePath.get(position - 1));
                Glide.with(context).load(file).centerCrop().into(mImageView);
            }
        }
    }

}
