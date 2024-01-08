package com.example.latihan;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class UpdateActivity extends AppCompatActivity {

    TextView id;
    EditText name;
    EditText qty;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update);
        id = findViewById(R.id.idProduct);
        name = findViewById(R.id.name);
        qty = findViewById(R.id.qty);
        Intent intent = getIntent();
        id.setText(intent.getStringExtra("idProduct"));
        name.setText(intent.getStringExtra("name"));
        qty.setText(intent.getStringExtra("qty"));


    }

    public void updateProduct(View view) {
        Product product = new Product();
        product.id = Integer.parseInt(id.getText().toString());
        product.name = name.getText().toString();
        product.qty = Integer.parseInt(qty.getText().toString());
        MsFunction msFunction = new MsFunction(this);
        msFunction.updateProduct(product);
        Intent toMainActivity  = new Intent(this, MainActivity.class);
        startActivity(toMainActivity);
    }
}