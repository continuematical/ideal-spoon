package com.example.sunset;

import android.animation.AnimatorSet;
import android.animation.ArgbEvaluator;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
import android.content.res.Resources;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;

public class SunsetFragment extends Fragment {
    private View mSceneView;
    private View mSkyView;
    private View mSunView;

    private int mBlueSkyColor;
    private int mSunsetSkyColor;
    private int mNightSkyColor;

    public static SunsetFragment newInstance() {
        return new SunsetFragment();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_sunset, container, false);
        mSceneView=view;
        mSkyView=view.findViewById(R.id.sky);
        mSunView=view.findViewById(R.id.sun);
        Resources resource=getResources();
        mBlueSkyColor=resource.getColor(R.color.blue_sky);
        mSunsetSkyColor=resource.getColor(R.color.sunset_sky);
        mNightSkyColor=resource.getColor(R.color.night_sky);

        mSceneView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startAnimation();
            }
        });
        return view;
    }
    private void startAnimation(){
        float sunYStart=mSunView.getTop();
        float sunYEnd=mSkyView.getHeight();
        ObjectAnimator heightAnimator=ObjectAnimator.ofFloat(mSunView,"y",sunYStart,sunYEnd)
                .setDuration(3200);
        heightAnimator.setInterpolator(new AccelerateInterpolator());

        ObjectAnimator sunsetAnimator=ObjectAnimator.ofInt(mSkyView,"backgroundColor",mBlueSkyColor,mSunsetSkyColor);
        //TypeEvaluator精确地计算开始到结束的递增值
        sunsetAnimator.setEvaluator(new ArgbEvaluator());

        ObjectAnimator nightSkyAnimator=ObjectAnimator.ofInt(mSkyView,"backgroundColor",mSunsetSkyColor,mNightSkyColor);
        nightSkyAnimator.setEvaluator(new ArgbEvaluator());
        AnimatorSet animatorSet=new AnimatorSet();
        animatorSet.play(heightAnimator).with(sunsetAnimator).before(nightSkyAnimator);
        animatorSet.start();
//        sunsetAnimator.start();
//        heightAnimator.start();
    }
}