package com.example.quicksidebar;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;

import com.example.quicksidebar.QuickSideBar.OnQuickSideBarTouchListener;
import com.example.quicksidebar.QuickSideBar.QuickSideBarTipsView;
import com.example.quicksidebar.QuickSideBar.QuickSideBarView;

import java.util.HashMap;

public class MainActivity extends AppCompatActivity implements OnQuickSideBarTouchListener {

    private RecyclerView recyclerView;
    QuickSideBarView quickSideBarView;
    QuickSideBarTipsView quickSideBarTipsView;
    HashMap<String, Integer> letters = new HashMap<>();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
    }

    void init() {
        recyclerView = findViewById(R.id.recycle_view);
        quickSideBarView = findViewById(R.id.QuickSideBarView);
        quickSideBarTipsView = findViewById(R.id.QuickSideBarTipsView);

        quickSideBarView.setListener(this);
    }

    @Override
    public void onLetterChanged(String letter, int position, float y) {

    }

    @Override
    public void onLetterTouching(boolean touching) {
        quickSideBarTipsView.setVisibility(touching ? View.VISIBLE : View.INVISIBLE);
    }

    private class CityListWithHeaderAdapter extends CityListAdapter<RecyclerView.ViewHolder> {

        @NonNull
        @Override
        public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            return null;
        }

        @Override
        public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {

        }
    }
}