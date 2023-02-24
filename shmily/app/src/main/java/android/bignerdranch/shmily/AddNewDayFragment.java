package android.bignerdranch.shmily;

import static android.app.Activity.RESULT_OK;


import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Switch;
import android.widget.TextView;

import java.util.Date;

public class AddNewDayFragment extends Fragment {
    private static final int REQUEST_DATE = 0;
    private static final String DIALOG = "dialog";

    private ImageButton preButton;
    private EditText name;
    private TextView dateText;
    private Switch reminder;
    private Switch top;
    private TextView store;

    private NewDay mNewDay = new NewDay();

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.activity_add_new_day, container, false);
        preButton = view.findViewById(R.id.pre_button);
        name = view.findViewById(R.id.name);
        dateText = view.findViewById(R.id.date);
        reminder = view.findViewById(R.id.remind_switch);
        top = view.findViewById(R.id.top_switch);
        store = view.findViewById(R.id.store);

        preButton.setOnClickListener(v -> {
            Intent intent = new Intent(getActivity(), MemorialDayActivity.class);
            startActivity(intent);
        });

        store.setOnClickListener(v -> {
            NewDayLab.get(getActivity()).addNewDay(mNewDay);
            Intent intent = new Intent(getActivity(), MemorialDayActivity.class);
            startActivity(intent);
        });

        name.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                mNewDay.setName(s.toString());
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });

        dateText.setOnClickListener(v -> {
            DatePickerFragment fragment = new DatePickerFragment();
            FragmentManager manager = getFragmentManager();
            fragment.setTargetFragment(AddNewDayFragment.this, REQUEST_DATE);
            fragment.show(manager, DIALOG);
        });


        reminder.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (isChecked) {
                mNewDay.setReminder(1);
            }
        });

        top.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (isChecked) {
                mNewDay.setReminder(1);
            }
        });

        return view;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (resultCode != RESULT_OK) {
            return;
        }
        if (requestCode == REQUEST_DATE) {
            Date date = (Date) data.getSerializableExtra(DatePickerFragment.DATE_RETURN);
            mNewDay.setDate(date);
            dateText.setText(date.toString());
        }
    }

}
