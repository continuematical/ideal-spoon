package com.example.criminalintent;

import androidx.fragment.app.Fragment;

public class CrimeListActivity extends SingleFragmentActivity{
    public Fragment CreateFragment(){
        return new CrimeListFragment();
    }
}
