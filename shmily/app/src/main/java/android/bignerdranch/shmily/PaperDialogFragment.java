package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.app.Dialog;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.core.content.ContextCompat;

public class PaperDialogFragment extends Dialog{

    public PaperDialogFragment(@NonNull Context context) {
        super(context);
    }

    public static class Builder{
        private TextView mText;
        private TextView mDate;
        private ImageButton mImageButton;
        private ImageView mImageView;

        private Context mContext;
        private Paper mPaper;

        public Builder(Context context,Paper paper) {
            mContext = context;
            mPaper=paper;
        }

        @SuppressLint("MissingInflatedId")
        public PaperDialogFragment create(){
            LayoutInflater inflater=(LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            View view=inflater.inflate(R.layout.fragment_paper_picker,null);
            PaperDialogFragment dialog=new PaperDialogFragment(mContext);
            dialog.addContentView(view,new WindowManager.LayoutParams(android.view.ViewGroup.LayoutParams.WRAP_CONTENT,ViewGroup.LayoutParams.WRAP_CONTENT));
            dialog.setContentView(view);
            mText=view.findViewById(R.id.paper_text_picker);
            mDate=view.findViewById(R.id.paper_date_picker);
            mImageButton=view.findViewById(R.id.return_paper);
            mImageView=view.findViewById(R.id.paper_picker_background);

            mText.setText(mPaper.getText());
            mDate.setText("--"+mPaper.getDate());
            mImageView.setBackgroundColor(ContextCompat.getColor(mContext,mPaper.getColor()));
            mImageButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialog.dismiss();
                }
            });

            Window window=dialog.getWindow();
            WindowManager.LayoutParams params=window.getAttributes();
            params.y=500;
            window.setAttributes(params);

            return dialog;
        }
    }
}
