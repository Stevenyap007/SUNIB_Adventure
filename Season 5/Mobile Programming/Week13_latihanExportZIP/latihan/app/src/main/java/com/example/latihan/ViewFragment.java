package com.example.latihan;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class ViewFragment extends Fragment {

    RecyclerView rvProduct;
    MsFunction functionProduct;
    public static ProductAdapter adapter;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_view, container, false);


        functionProduct = new MsFunction(getContext());
        rvProduct = view.findViewById(R.id.rvProduct);
        rvProduct.setLayoutManager(new LinearLayoutManager(getContext()));

        adapter = new ProductAdapter(getContext());
        adapter.setListProduct(functionProduct.getAllProduct());
        rvProduct.setAdapter(adapter);
        return  view;
    }
}