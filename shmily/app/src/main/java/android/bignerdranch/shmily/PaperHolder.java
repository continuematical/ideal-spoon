package android.bignerdranch.shmily;

import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.FragmentManager;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Fragment;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Paint;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;


@SuppressLint("ValidFragment")
public class PaperHolder implements View.OnClickListener{
    private static final String DIALOG_PAPER = "dialog_paper";

    private Context mContext;
    private ImageView mImageView;
    private TextView mDate;
    private Paper mPaper;

    public PaperHolder(View view, Context context, Paper paper) {
        mContext = context;
        mPaper = paper;
        mImageView = view.findViewById(R.id.color_paper);
        mDate = view.findViewById(R.id.paper_date);
    }

    public void onBind() {
        changeBackground(mPaper.getColor());
        mImageView.setOnClickListener(this);
        mDate.setText(mPaper.getDate());
    }

    @SuppressLint("ResourceType")
    @Override
    public void onClick(View view) {
        PaperDialogFragment.Builder builder=new PaperDialogFragment.Builder(mContext,mPaper);
        builder.create().show();
    }

    public void changeBackground(int color){
        switch (color){
            case R.color.green:
                paintPicture(mContext,R.drawable.green_paper);
                break;
            case R.color.blue:
                paintPicture(mContext,R.drawable.blue_paper);
                break;
            case R.color.pink:
                paintPicture(mContext,R.drawable.pink_paper);
                break;
            case R.color.light_green:
                paintPicture(mContext,R.drawable.light_green_paper);
                break;
            case R.color.red:
                paintPicture(mContext,R.drawable.red_paper);
                break;
            default:
                paintPicture(mContext,R.drawable.yellow_paper);
                break;
        }
    }

    public void paintPicture(Context context,int id){
        Drawable drawable= ContextCompat.getDrawable(context,id);
        mImageView.setBackground(drawable);
    }
}
