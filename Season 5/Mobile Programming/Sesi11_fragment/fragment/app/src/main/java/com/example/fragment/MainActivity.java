package com.example.fragment;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTransaction;


import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity implements FoodListFragment.FoodlistListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //FoodDetailFragment fdf = (FoodDetailFragment) getSupportFragmentManager()
        //        .findFragmentById(R.id.detailFragment);
        //fdf.setId(0);
    }

    @Override
    public void itemClicked(int id) {
        View fragmentContainer = findViewById(R.id.container);

        if(fragmentContainer!=null){
            //untuk tablet
            FoodDetailFragment fdf = new FoodDetailFragment();
            fdf.setId(id);
            FragmentTransaction ft = getSupportFragmentManager().beginTransaction();
            ft.replace(R.id.container,fdf);
            ft.addToBackStack(null);
            ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
            ft.commit();
        }else{
            //untuk layout dalam phone
            //buka activity lain
        }


    }
}