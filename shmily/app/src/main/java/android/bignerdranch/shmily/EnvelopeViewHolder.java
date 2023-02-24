package android.bignerdranch.shmily;

import android.content.ClipData;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.view.menu.MenuView;
import androidx.recyclerview.widget.RecyclerView;

public class EnvelopeViewHolder extends RecyclerView.ViewHolder {
    private TextView mDate;
    private TextView mText;
    private ImageView mImage;

    public EnvelopeViewHolder(LayoutInflater layoutInflater, ViewGroup parent) {
        super(layoutInflater.inflate(R.layout.fragment_envelope_item,parent,false));
        mDate= itemView.findViewById(R.id.envelope_text);
        mText=itemView.findViewById(R.id.envelope_date);
        mImage=itemView.findViewById(R.id.envelope_image);
    }

    public void bind(){

    }
}
