package android.bignerdranch.shmily;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.DiffUtil;
import androidx.recyclerview.widget.ListAdapter;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class PaperAdapter extends BaseAdapter {
    private Context mContext;
    private List<Paper> mPapers;

    public PaperAdapter(Context context, List<Paper> papers) {
        mContext = context;
        mPapers = papers;
    }

    @Override
    public int getCount() {
        return mPapers.size();
    }

    @Override
    public Object getItem(int i) {
        return mPapers.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        PaperHolder holder = null;
        LayoutInflater inflater = LayoutInflater.from(mContext);
        Paper paper = mPapers.get(i);
        if (view == null) {
            view = inflater.inflate(R.layout.list_item_paper, viewGroup, false);
            holder = new PaperHolder(view,mContext,paper);
            view.setTag(holder);
        }else{
            holder=(PaperHolder) view.getTag();
        }
        holder.onBind();
        return view;
    }

    public void setPapers(List<Paper> papers){
        mPapers=papers;
    }
}

