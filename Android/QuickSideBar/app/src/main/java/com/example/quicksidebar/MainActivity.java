package com.example.quicksidebar;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.quicksidebar.QuickSideBar.OnQuickSideBarTouchListener;
import com.example.quicksidebar.QuickSideBar.QuickSideBarTipsView;
import com.example.quicksidebar.QuickSideBar.QuickSideBarView;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import com.timehop.stickyheadersrecyclerview.StickyRecyclerHeadersAdapter;
import com.timehop.stickyheadersrecyclerview.StickyRecyclerHeadersDecoration;

import java.lang.reflect.Type;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

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

        final LinearLayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        recyclerView.setLayoutManager(layoutManager);

        CityListWithHeaderAdapter adapter = new CityListWithHeaderAdapter();

        //GSON解析
        Type type = new TypeToken<LinkedList<City>>() {
        }.getType();
        Gson gson = new Gson();
        LinkedList<City> cities = gson.fromJson(DataConstants.cityDataList, type);

        ArrayList<String> customerLetters = new ArrayList<>();//首字母集合，默认为 26 位字母

        int position = 0;
        for (City city : cities) {
            String letter = city.getFirstLetter();
            if (!letters.containsKey(letter)) {
                //letters初始化
                letters.put(letter, position);
                customerLetters.add(letter);
            }
            position++;
        }

        //不自定义则默认26个字母
        quickSideBarView.setLetters(customerLetters);
        adapter.addAll(cities);
        recyclerView.setAdapter(adapter);

        final StickyRecyclerHeadersDecoration headersDecor = new StickyRecyclerHeadersDecoration(adapter);
        adapter.registerAdapterDataObserver(new RecyclerView.AdapterDataObserver() {
            @Override
            public void onChanged() {
                headersDecor.invalidateHeaders();
            }
        });
        recyclerView.addItemDecoration(headersDecor);

        // Add decoration for dividers between list items
        recyclerView.addItemDecoration(new DividerDecoration(this));
    }

    void init() {
        recyclerView = findViewById(R.id.recycle_view);
        quickSideBarView = findViewById(R.id.QuickSideBarView);
        quickSideBarTipsView = findViewById(R.id.QuickSideBarTipsView);

        quickSideBarView.setListener(this);
    }

    @Override
    public void onLetterChanged(String letter, int position, float y) {
        quickSideBarTipsView.setText(letter, position, y);
        //有此key则获取位置并滚动到该位置
        if (letters.containsKey(letter)) {
            recyclerView.scrollToPosition(letters.get(letter));
        }
    }

    @Override
    public void onLetterTouching(boolean touching) {
        quickSideBarTipsView.setVisibility(touching ? View.VISIBLE : View.INVISIBLE);
    }

    private class CityListWithHeaderAdapter extends CityListAdapter<RecyclerView.ViewHolder>
            implements StickyRecyclerHeadersAdapter {

        @NonNull
        @Override
        public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.view_item, parent, false);
            return new RecyclerView.ViewHolder(view) {
                @Override
                public String toString() {
                    return super.toString();
                }
            };
        }

        @Override
        public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
            TextView textView = (TextView) holder.itemView;
            textView.setText(getItem(position).getName());
        }

        @Override
        public long getHeaderId(int position) {
            return getItem(position).getFirstLetter().charAt(0);
        }

        @Override
        public RecyclerView.ViewHolder onCreateHeaderViewHolder(ViewGroup parent) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.view_item, parent, false);
            return new RecyclerView.ViewHolder(view) {
                @Override
                public String toString() {
                    return super.toString();
                }
            };
        }

        @Override
        public void onBindHeaderViewHolder(RecyclerView.ViewHolder holder, int position) {
            TextView textView = (TextView) holder.itemView;
            textView.setText(String.valueOf(getItem(position).getFirstLetter()));
            holder.itemView.setBackgroundColor(getRandomColor());
        }

        private int getRandomColor() {
            SecureRandom random = new SecureRandom();
            return Color.HSVToColor(150, new float[]{random.nextInt(359), 1, 1});
        }
    }
}