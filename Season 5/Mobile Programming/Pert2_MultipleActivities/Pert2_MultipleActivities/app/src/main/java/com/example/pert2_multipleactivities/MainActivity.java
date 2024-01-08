package com.example.pert2_multipleactivities;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    EditText pesan;
    EditText nama;
    EditText telpon;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        pesan = findViewById(R.id.editTextPesan);
        nama = findViewById(R.id.editTextNama);
        telpon = findViewById(R.id.editTextTelpon);
    }

    public void openActivity(View view) {
        Intent openActivityIntent = new Intent(this,OpenActivity.class);
        startActivity(openActivityIntent);
    }

    public void SendMessage(View view) {
        Intent send = new Intent(this,TerimaPesan.class);
        send.putExtra("pesan",pesan.getText().toString());
        send.putExtra("nama",nama.getText().toString());
        send.putExtra("telpon",telpon.getText().toString());

        startActivity(send);
    }
}