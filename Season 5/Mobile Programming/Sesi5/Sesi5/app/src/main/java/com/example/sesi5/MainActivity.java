package com.example.sesi5;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ArrayList <Book> listBook;
    RecyclerView rvBook;

    BookAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listBook = new ArrayList<>();
        rvBook = findViewById(R.id.rvBook);

        Book book1 = new Book();
        book1.title = "Belajar Pemorgraman android untuk semua kebutuhan";
        book1.author = "Ir. Yuniar Sukardi";
        book1.price = 90000;
        book1.image = R.drawable.android;

        Book book2 = new Book();
        book2.title = "Bermain Android studio itu mudah";
        book2.author = "Abdul Aziz";
        book2.price = 85000;
        book2.image = R.drawable.android2;

        Book book3 = new Book();
        book3.title = "Belajar Coding Android untuk pemula";
        book3.author = "Ir. Yuniar Sukardi";
        book3.price = 70000;
        book3.image = R.drawable.android3;

//        rvBook.setLayoutManager(new LinearLayoutManager(this));
        rvBook.setLayoutManager(new GridLayoutManager(this,2));
        for(int i = 0; i< 20; i++) {
            listBook.add(book1);
            listBook.add(book2);
            listBook.add(book3);
        }

        adapter = new BookAdapter(this, listBook);
        rvBook.setAdapter(adapter);
    }
}