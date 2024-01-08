package com.example.fragment;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.TextureView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class FoodDetailFragment extends Fragment {



    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_food_detail, container, false);
    }

    int id;

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public void onStart() {
        super.onStart();
        View view = getView();

        Food food = Food.foods[id];
        TextView name = view.findViewById(R.id.name);
        name.setText(food.getName());
        TextView desc = view.findViewById(R.id.desc);
        desc.setText(food.getDesc());
    }
}