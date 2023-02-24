package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.TextView;


import java.util.List;

public class InterestListActivity extends AppCompatActivity implements View.OnClickListener {
    private ImageButton write;
    private ImageButton preButton;

    private RecyclerView mRecyclerView;
    private InterestAdapter mAdapter;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_interset);
        write = findViewById(R.id.write_he_she);
        preButton = findViewById(R.id.pre_button);

        mRecyclerView = findViewById(R.id.write_about_list_recycle_view);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(InterestListActivity.this));
        updateInterest();

        write.setOnClickListener(this);
        preButton.setOnClickListener(this);
    }

    public void updateInterest() {
        InterestLab sInterestLab = InterestLab.get(InterestListActivity.this);
        List<Interest> interests = sInterestLab.getInterests();
        if (mAdapter == null) {
            mAdapter = new InterestAdapter(interests);
            mRecyclerView.setAdapter(mAdapter);
        } else {
            mAdapter.notifyDataSetChanged();
            mAdapter.setInterests(interests);
        }
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.write_he_she:
                Intent intent = new Intent(InterestListActivity.this, WriteInterestActivity.class);
                startActivity(intent);
                break;
            case R.id.pre_button:
                Intent returnMemory = new Intent(InterestListActivity.this, MemoryActivity.class);
                startActivity(returnMemory);
                break;
        }
    }

    private class InterestAdapter extends RecyclerView.Adapter<InterestHolder> {
        private List<Interest> mInterests;

        public InterestAdapter(List<Interest> interests) {
            mInterests = interests;
        }

        @NonNull
        @Override
        public InterestHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            LayoutInflater inflater = LayoutInflater.from(InterestListActivity.this);
            InterestHolder holder = new InterestHolder(inflater, parent);
            return holder;
        }

        @Override
        public void onBindViewHolder(@NonNull InterestHolder holder, int position) {
            Interest interest = mInterests.get(position);
            holder.Bind(interest);
        }

        @Override
        public int getItemCount() {
            return mInterests.size();
        }

        public void setInterests(List<Interest> interests) {
            mInterests = interests;
        }
    }

    private class InterestHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        private TextView mTextView;
        private Interest mInterest;

        public InterestHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.fragment_interest_item, parent, false));
            mTextView = itemView.findViewById(R.id.about_he_she);
            itemView.setOnClickListener(this);
        }

        @SuppressLint("ResourceAsColor")
        public void Bind(Interest interest) {
            mInterest = interest;
            mTextView.setText(mInterest.getTitle());
        }

        @Override
        public void onClick(View view) {
            Intent intent = WriteInterestActivity.newInstance(InterestListActivity.this, mInterest.getUUID());
            startActivity(intent);
        }
    }
}