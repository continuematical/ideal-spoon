package com.example.criminalintent;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;
import androidx.fragment.app.FragmentStatePagerAdapter;
import androidx.viewpager.widget.ViewPager;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import java.util.List;
import java.util.UUID;

public class CrimePagerActivity extends AppCompatActivity {
    private final static String EXTRA_CRIME_ID="com.example.criminalintent.crime_id";
    private ViewPager mViewPager;
    private List<Crime> mCrimes;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_crime_pager);

        UUID uuid=(UUID)getIntent().getSerializableExtra(EXTRA_CRIME_ID);
        mViewPager=(ViewPager) findViewById(R.id.activity_crime_pager_view_pager);
        mCrimes=CrimeLab.get(this).getCrimes();
        FragmentManager manager=getSupportFragmentManager();
        //管理于Adapter的对话并协同工作
        mViewPager.setAdapter(new FragmentStatePagerAdapter(manager) {
            @NonNull
            @Override
            //获取并显示crimes数组里指定位置的crime，会返回配置过的CrimeFragment来显示指定的crime
            public Fragment getItem(int position) {
                Crime crime=mCrimes.get(position);
                return CrimeFragment.newInstance(crime.getId());
            }

            @Override
            public int getCount() {
                return mCrimes.size();
            }
        });
    }

    public static Intent newInstance(Context packageContext, UUID uuid){
        Intent intent=new Intent(packageContext,CrimePagerActivity.class);
        intent.putExtra(EXTRA_CRIME_ID,uuid);
        return intent;
    }
}