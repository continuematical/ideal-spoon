package android.bignerdranch.shmily;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;
import android.widget.ImageButton;

import java.util.List;

public class PaperListFragment extends Fragment {
    private static final String EXTRA_PAPER = "paper";
    private GridView mGridView;
    private PaperAdapter mAdapter;
    private ImageButton preButton;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @SuppressLint("MissingInflatedId")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_paper_list, container, false);
        mGridView = v.findViewById(R.id.paper_list_gridView);
        preButton = v.findViewById(R.id.pre_button);
        preButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getActivity(), LookAtTheActivity.class);
                startActivity(intent);
            }
        });
        updateView();

        return v;
    }

    public void updateView() {
        PaperLab Lab = PaperLab.get(getActivity());
        List<Paper> papers = Lab.getPapers();
        if (mAdapter == null) {
            mAdapter = new PaperAdapter(getActivity(), papers);
            mGridView.setAdapter(mAdapter);
        } else {
            mAdapter.setPapers(papers);
            mAdapter.notifyDataSetChanged();
        }
    }

}