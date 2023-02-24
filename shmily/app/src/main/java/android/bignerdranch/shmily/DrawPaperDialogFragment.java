package android.bignerdranch.shmily;


import static android.bignerdranch.shmily.R.*;

import android.annotation.SuppressLint;
import android.app.Dialog;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.TextView;

import androidx.annotation.NonNull;

import java.util.List;
import java.util.Random;


public class DrawPaperDialogFragment extends Dialog {

    public DrawPaperDialogFragment(@NonNull Context context) {
        super(context);
    }

    public static class Builder {
        private TextView text;
        private TextView date;
        private TextView returnStore;
        private Context mContext;
        private List<Paper> mPapers;

        public Builder(Context mContext, List<Paper> mPapers) {
            this.mContext = mContext;
            this.mPapers = mPapers;
        }

        @SuppressLint("MissingInflatedId")
        public DrawPaperDialogFragment create() {
            Random random = new Random();
            int number = random.nextInt() % mPapers.size();
            Paper paper = mPapers.get(number);

            LayoutInflater inflater = LayoutInflater.from(mContext);
            View view = inflater.inflate(layout.activity_draw_paper_dialog, null);
            DrawPaperDialogFragment dialog = new DrawPaperDialogFragment(mContext);
            dialog.addContentView(view, new WindowManager.LayoutParams(android.view.ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            dialog.setContentView(view);

            text = view.findViewById(id.paper_text);
            date = view.findViewById(id.paper_date);
            returnStore = view.findViewById(id.return_store);
            returnStore.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    dialog.dismiss();
                }
            });

            text.setText(paper.getText());
            date.setText(paper.getDate());
            return dialog;
        }
    }
}
