package android.bignerdranch.shmily;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.TextView;

import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

public class MemorialDayActivity extends AppCompatActivity implements View.OnClickListener {
    private ImageButton preButton;
    private ImageButton add;
    private RecyclerView mRecyclerView;

    private MemorialDayAdapter mAdapter;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_memorial_day);
        preButton = findViewById(R.id.pre_button);
        add = findViewById(R.id.add_new_day);
        mRecyclerView = findViewById(R.id.new_day_list_recycle_view);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(MemorialDayActivity.this));

        preButton.setOnClickListener(this);
        add.setOnClickListener(this);
        update();
    }

    public void update() {
        List list = NewDayLab.get(MemorialDayActivity.this).getNewDays();
        List mNewDays = sortTop(list);
        if (mAdapter == null) {
            mAdapter = new MemorialDayAdapter(mNewDays);
            mRecyclerView.setAdapter(mAdapter);
        } else {
            mAdapter.notifyDataSetChanged();
            mAdapter.setNewDays(mNewDays);
        }
    }

    public List sortTop(List list) {
        Collections.sort(list, new Comparator<NewDay>() {
            @Override
            public int compare(NewDay o1, NewDay o2) {
                if (o1.getTop() == 1 && o2.getTop() == 1) {
                    return (int) (o1.calculateTime() - o2.calculateTime());
                } else {
                    return o2.getTop() - o1.getTop();
                }
            }
        });
        return list;
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.add_new_day:
                Intent addNewDayIntent = new Intent(MemorialDayActivity.this, AddNewDayActivity.class);
                startActivity(addNewDayIntent);
                break;
            case R.id.pre_button:
                Intent preIntent = new Intent(MemorialDayActivity.this, MemoryActivity.class);
                startActivity(preIntent);
                break;
        }
    }


    private class MemorialDayAdapter extends RecyclerView.Adapter<MemorialDayHolder> {
        private List<NewDay> mNewDays;

        public MemorialDayAdapter(List<NewDay> mNewDays) {
            this.mNewDays = mNewDays;
        }

        @NonNull
        @Override
        public MemorialDayHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            LayoutInflater inflater = LayoutInflater.from(MemorialDayActivity.this);
            return new MemorialDayHolder(inflater, parent);
        }

        @Override
        public void onBindViewHolder(@NonNull MemorialDayHolder holder, int position) {
            NewDay newDay = mNewDays.get(position);
            holder.bind(newDay);
        }

        @Override
        public int getItemCount() {
            return mNewDays.size();
        }

        public void setNewDays(List<NewDay> mNewDays) {
            this.mNewDays = mNewDays;
        }
    }

    private class MemorialDayHolder extends RecyclerView.ViewHolder {
        private TextView memorialThing;
        private TextView number;
        private NewDay mNewDay;

        public MemorialDayHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.new_day_item, parent, false));
            memorialThing = itemView.findViewById(R.id.memorial_thing);
            number = itemView.findViewById(R.id.number);
        }

        public void bind(NewDay newDay) {
            mNewDay = newDay;
            long days = newDay.calculateTime();
            memorialThing.setText("距离 " + mNewDay.getName() + " 还有");
            number.setText(days + " 天");
        }
    }
}