package com.example.sesi5;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class BookAdapter extends RecyclerView.Adapter <BookAdapter.ViewHolder> {
    Context cx;
    ArrayList <Book> listBook;

    public BookAdapter(Context cx, ArrayList <Book> listBook){
        this.cx = cx;
        this.listBook = listBook;
    }

    @NonNull
    @Override
    public BookAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(cx).inflate(R.layout.list_book_item,parent,false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull BookAdapter.ViewHolder holder, int position) {
        Book book = listBook.get(position);
        holder.itemImage.setImageResource(book.image);
        holder.itemDescription.setText(book.title + "\n" + book.author + "\n" + book.price);
    }

    @Override
    public int getItemCount() {
        return listBook.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{
        ImageView itemImage;
        TextView itemDescription;
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            itemImage = itemView.findViewById(R.id.image);
            itemDescription = itemView.findViewById(R.id.description);
            itemView.setOnClickListener(this);
        }

        @Override
        public void onClick(View v) {
            int position = getAdapterPosition();
            Book book = listBook.get(position);
            Toast.makeText(cx, book.author + " " + book.price, Toast.LENGTH_LONG).show();
        }
    }
}
