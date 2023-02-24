package android.bignerdranch.shmily;


import static android.bignerdranch.shmily.R.*;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

public class MyPostOfficeFragment extends Fragment implements View.OnClickListener{
    private RecyclerView mRecyclerView;
    private EnvelopeAdapter mAdapter;
    private EnvelopeViewHolder mViewHolder;

    private ImageButton writeEnvelope;
    private ImageButton preButton;
    @SuppressLint("MissingInflatedId")
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view=inflater.inflate(layout.fragment_my_post_office,container,false);
        writeEnvelope=view.findViewById(R.id.write_envelope);
        preButton=view.findViewById(id.pre_button);

        mRecyclerView= view.findViewById(R.id.envelope_list_recycle_view);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(getActivity()));

        writeEnvelope.setOnClickListener(this);
        preButton.setOnClickListener(this);
        return view;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.pre_button:
                Intent returnPostOffice=new Intent(getActivity(),MemoryActivity.class);
                startActivity(returnPostOffice);
                break;
            case R.id.write_envelope:
                Intent writeEnvelope=new Intent(getActivity(),WriteEnvelopeActivity.class);
                startActivity(writeEnvelope);
                break;
        }
    }
}
