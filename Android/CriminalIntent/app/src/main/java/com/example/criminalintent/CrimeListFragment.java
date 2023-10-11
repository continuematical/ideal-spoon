package com.example.criminalintent;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.text.format.DateFormat;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class CrimeListFragment extends Fragment implements View.OnClickListener {
    private RecyclerView mCrimeRecyclerView;
    private CrimeAdapter mAdapter;
    private ImageView mSolvedImageView;
    private Button NewCrime;
    //新建跟踪记录子标题状态栏里的成员变量
    private boolean mSubtitleVisible;
    //保存子标题状态值
    private static final String SAVED_SUBTITLE_VISIBLE = "subtitle";

    @SuppressLint("MissingInflatedId")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle saveInstanceState) {
        View view = inflater.inflate(R.layout.fragment_crime_list, container, false);
        //RecyclerView的任务仅限于回收和定位屏幕上的View
        mCrimeRecyclerView = view.findViewById(R.id.crime_recycler_view);
        NewCrime = view.findViewById(R.id.new_crime);
        NewCrime.setOnClickListener(this);
        //RecyclerView视图创建完后，将委托的任务交给了LayoutManager：摆放屏幕上的列表项，滚动屏幕
        mCrimeRecyclerView.setLayoutManager(new LinearLayoutManager(getActivity()));
        //以竖直列表的形式展示列表项
        updateUI();
        return view;
    }

    @Override
    public void onClick(View view) {
        Crime crime = new Crime();
        CrimeLab.get(getActivity()).addCrime(crime);
        Intent intent = new Intent(getActivity(), CrimePagerActivity.class);
        startActivity(intent);
    }

    public void updateSubtitle() {
        CrimeLab lab = CrimeLab.get(getContext());
        int CrimeCount = lab.getCrimes().size();
        AppCompatActivity activity = (AppCompatActivity) getActivity();
        String subtitle = getResources().getQuantityString(R.plurals.subtitle_plural, CrimeCount, CrimeCount);
        if (!mSubtitleVisible) {
            subtitle = null;
        }
        activity.getSupportActionBar().setSubtitle(subtitle);
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //通知fragmentManager onCreateOptionsMenu()方法请求
        setHasOptionsMenu(true);
    }

    @Override
    public void onResume() {
        super.onResume();
        updateUI();
    }

    //保存子标题状态值
    @Override
    public void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putBoolean(SAVED_SUBTITLE_VISIBLE, mSubtitleVisible);
    }

    //创建菜单方法,由FragmentManager负责调用
    @Override
    public void onCreateOptionsMenu(@NonNull Menu menu, @NonNull MenuInflater inflater) {
        super.onCreateOptionsMenu(menu, inflater);
        inflater.inflate(R.menu.fragment_crime_list, menu);

        MenuItem subtitleItem = menu.findItem(R.id.show_subtitle);
        if (mSubtitleVisible) {
            subtitleItem.setTitle(R.string.hide_subtitle);
        } else {
            subtitleItem.setTitle(R.string.show_subtitle);
        }
    }

    //相应菜单单项选择事件
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.new_crime:
                Crime crime = new Crime();
                CrimeLab.get(getActivity()).addCrime(crime);
                Intent intent = CrimePagerActivity.newInstance(getActivity(), crime.getId());
                startActivity(intent);
                return true;
            case R.id.show_subtitle:
                mSubtitleVisible = !mSubtitleVisible;
                getActivity().invalidateOptionsMenu();
                updateSubtitle();
                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }

    public void updateUI() {
        CrimeLab crimeLab = CrimeLab.get(getActivity());
        List<Crime> crimes = crimeLab.getCrimes();
        if (mAdapter == null) {
            mAdapter = new CrimeAdapter(crimes);
            mCrimeRecyclerView.setAdapter(mAdapter);
        } else {
            mAdapter.setCrimes(crimes);
            mAdapter.notifyDataSetChanged();
        }

        if (crimes.size() > 0) {
            NewCrime.setVisibility(View.INVISIBLE);
        }
        updateSubtitle();
    }

    //定义ViewHolder内部类
    //任务：容纳view视图
    private class CrimeHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        private TextView mTitleTextView;
        private TextView mDateTextView;
        private Crime mCrime;

        public CrimeHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.list_item_crime, parent, false));
            mTitleTextView = itemView.findViewById(R.id.crime_title);
            mDateTextView = itemView.findViewById(R.id.crime_date);
            mSolvedImageView = itemView.findViewById(R.id.crime_solved);
            itemView.setOnClickListener(this);
        }

        public void bind(Crime crime) {
            mCrime = crime;
            mTitleTextView.setText(mCrime.getTitle());
            CharSequence date = DateFormat.format("MMM dd,yyyy", mCrime.getDate());
            mDateTextView.setText(date);
            mSolvedImageView.setVisibility(mCrime.isSolved() ? View.VISIBLE : View.GONE);
        }

        public void onClick(View view) {
            Intent intent = CrimePagerActivity.newInstance(getActivity(), mCrime.getId());
            startActivity(intent);
        }
    }

    //定义Adapter内部类：控制器对象
    //任务：创建必要的ViewHolder；绑定必要的ViewHolder至模型数据
    private class CrimeAdapter extends RecyclerView.Adapter<CrimeHolder> {
        private List<Crime> mCrimes;

        public CrimeAdapter(List<Crime> crimes) {
            mCrimes = crimes;
        }

        @NonNull
        @Override
        public CrimeHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            LayoutInflater layoutInflater = LayoutInflater.from(getActivity());
            return new CrimeHolder(layoutInflater, parent);
        }

        public void onBindViewHolder(@NonNull CrimeHolder holder, int position) {
            Crime crime = mCrimes.get(position);
            holder.bind(crime);
        }

        @Override
        public int getItemCount() {
            return mCrimes.size();
        }

        public void setCrimes(List<Crime> crimes) {
            mCrimes = crimes;
        }
    }
}
