package com.example.fragment;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.ListFragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;


public class FoodListFragment extends ListFragment {

    static interface FoodlistListener{
        void itemClicked(int id);
    }

    FoodlistListener listener;

    @Override
    public void onAttach(@NonNull Context context) {
        super.onAttach(context);
        this.listener = (FoodlistListener) context;
    }

    @Override
    public void onListItemClick(@NonNull ListView l, @NonNull View v, int position, long id) {
        if(listener!=null){
            listener.itemClicked((int) id);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        String[] names = new String[Food.foods.length];

        for(int i=0 ; i<names.length;i++){
            names[i] = Food.foods[i].getName();
        }

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                inflater.getContext(), android.R.layout.simple_list_item_1,names
        );

        setListAdapter(adapter);

        return super.onCreateView(inflater,container,savedInstanceState);
        //return inflater.inflate(R.layout.fragment_food_list, container, false);
    }
}