package com.example.latihan;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class InsertFragment extends Fragment {
    EditText name;
    EditText qty;
    MsFunction functionProduct;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_insert, container, false);

        name = view.findViewById(R.id.name);
        qty = view.findViewById(R.id.qty);

        Button btnSimpan = view.findViewById(R.id.btnInsert);
        btnSimpan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Product product = new Product();
                functionProduct = new MsFunction(getContext());
                product.name = name.getText().toString();
                product.qty = Integer.parseInt(qty.getText().toString());
                functionProduct.insertProduct(product);

                ViewFragment.adapter.setListProduct(functionProduct.getAllProduct());
                Toast.makeText(getContext(), "Data Berhasil diinput!", Toast.LENGTH_SHORT).show();
                name.setText("");
                qty.setText("");
            }
        });


        return view;
    }



}