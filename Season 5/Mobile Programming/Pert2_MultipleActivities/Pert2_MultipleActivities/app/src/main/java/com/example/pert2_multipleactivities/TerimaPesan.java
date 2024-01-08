package com.example.pert2_multipleactivities;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class TerimaPesan extends AppCompatActivity {
    TextView terimaPesan;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_terima_pesan);
        terimaPesan = findViewById(R.id.textViewTerimaPesan);


        Intent terimaIntent = getIntent();
        String pesan = terimaIntent.getStringExtra("pesan");
        String nama = terimaIntent.getStringExtra("nama");
        String telpon = terimaIntent.getStringExtra("telpon");
        terimaPesan.setText(
                pesan + "\n" +
                nama + "\n" +
                telpon);
    }
}