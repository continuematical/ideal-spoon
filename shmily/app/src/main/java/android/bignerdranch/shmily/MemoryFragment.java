package android.bignerdranch.shmily;

import androidx.annotation.Nullable;

import androidx.fragment.app.Fragment;

import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.Calendar;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.List;
import java.util.Set;

public class MemoryFragment extends Fragment {
    private TextView PaperStore;
    private TextView MyPostOffice;
    private TextView MemorialDay;
    private TextView AboutHeShe;
    private TextView reminder;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.activity_memory, container, false);
        PaperStore = view.findViewById(R.id.my_paper_storage);
        MyPostOffice = view.findViewById(R.id.my_post_office);
        MemorialDay = view.findViewById(R.id.memorial_day);
        AboutHeShe = view.findViewById(R.id.about_he_she);
        reminder = view.findViewById(R.id.remind);

        updateReminder();

        setOnClick();
        return view;
    }

    public void updateReminder() {
        List<NewDay> list = NewDayLab.get(getActivity()).getNewDays();
        List<NewDay> newDays = sortReminder(list);
        for (NewDay day : newDays) {
            if (day.getReminder() == 1) {
                reminder.setText("距离 " + day.getName() + " 还有 " + day.calculateTime() + " 天");
                break;
            }
        }
    }

    public List sortReminder(List list) {
        Collections.sort(list, new Comparator<NewDay>() {
            @Override
            public int compare(NewDay o1, NewDay o2) {
                return (int) (o1.calculateTime() - o2.calculateTime());
            }
        });
        return list;
    }

    @Override
    public void onResume() {
        super.onResume();
        updateReminder();
    }

    private void setOnClick() {
        onClick onClick = new onClick();
        PaperStore.setOnClickListener(onClick);
        MyPostOffice.setOnClickListener(onClick);
        AboutHeShe.setOnClickListener(onClick);
        MemorialDay.setOnClickListener(onClick);
    }

    private class onClick implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.my_paper_storage:
                    Intent paperStoreIntent = new Intent(getActivity(), MyPaperStorageActivity.class);
                    startActivity(paperStoreIntent);
                    break;
                case R.id.my_post_office:
                    Intent postOfficeIntent = new Intent(getActivity(), MyPostOfficeActivity.class);
                    startActivity(postOfficeIntent);
                    break;
                case R.id.about_he_she:
                    Intent interestIntent = new Intent(getActivity(), InterestListActivity.class);
                    startActivity(interestIntent);
                    break;
                default:
                    Intent memorialDayIntent = new Intent(getActivity(), MemorialDayActivity.class);
                    startActivity(memorialDayIntent);
                    break;
            }
        }
    }
}