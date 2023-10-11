package com.example.quicksidebar;

import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;

public abstract class CityListAdapter<VH extends RecyclerView.ViewHolder> extends RecyclerView.Adapter<VH> {
    private ArrayList<City> items = new ArrayList<>();

    public CityListAdapter() {
        setHasStableIds(true);
    }

    public void add(City object) {
        items.add(object);
        notifyDataSetChanged();
    }

    public void add(int index, City Object) {
        items.add(index, Object);
        notifyDataSetChanged();
    }

    public void addAll(Collection<? extends City> collection) {
        if (collection != null) {
            items.addAll(collection);
            notifyDataSetChanged();
        }
    }

    public void addAll(City... item) {
        addAll(Arrays.asList(item));
    }

    public void remove(String object) {
        items.remove(object);
        notifyDataSetChanged();
    }

    public void clear() {
        items.clear();
        notifyDataSetChanged();
    }

    public City getItem(int position) {
        return items.get(position);
    }

    public long getItemId(int position) {
        return getItem(position).hashCode();
    }

    public int getItemCount() {
        return items.size();
    }
}
