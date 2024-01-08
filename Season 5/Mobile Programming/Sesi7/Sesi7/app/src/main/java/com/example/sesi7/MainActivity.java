package com.example.sesi7;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    FunctionDB functionDB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        functionDB = new FunctionDB(this);
        Product product = new Product();
//        product.name = "Pulpen";
//        product.qty = 12;
//        functionDB.insert(product);
//
//        product.name = "Pulpen2";
//        product.qty = 30;
//        functionDB.insert(product);

//        functionDB.delete(3);

        Product product2 = new Product();
        product2.id = 4;
        product2.name = "Pulpen & Penghapus";
        product2.qty = 100;
        functionDB.insert(product2);


        ArrayList <Product> listProduct = functionDB.getAllPoduct();
        String text = "";
        for(int i=0; i < functionDB.getAllPoduct().size(); i++){
            text = text +
                    " " +listProduct.get(i).id +
                    " " +listProduct.get(i).name +
                    " " +listProduct.get(i).qty +
                    "\n";
        }

        TextView view = findViewById(R.id.view);
        view.setText(text);
    }
}