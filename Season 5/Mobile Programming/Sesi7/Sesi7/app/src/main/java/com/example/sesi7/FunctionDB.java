package com.example.sesi7;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;

public class FunctionDB {
    DBHelper dbHelper;

    public FunctionDB(Context ctx){
        dbHelper = new DBHelper(ctx,"DatabaseAplikasi",null,1);

    }
    public void insert(Product product){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put("name",product.name);
        cv.put("qty",product.qty);
        db.insert("msproduct",null,cv);
        db.close();
    }

    @SuppressLint("Range")
    public ArrayList<Product> getAllPoduct(){
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        ArrayList <Product> listProduct = new ArrayList<>();
        Cursor cursor = db.rawQuery("select * from msproduct",null);
        Product product = null;
        while(cursor.moveToNext()){
            product = new Product();
            product.id = cursor.getInt(cursor.getColumnIndex("id"));
            product.name = cursor.getString(cursor.getColumnIndex("name"));
            product.qty = cursor.getInt(cursor.getColumnIndex("qty"));
            listProduct.add(product);
        }
        return listProduct;
    }

    public void delete(int id){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        String [] selectionArgs = {""+id};
        db.delete("msproduct","od = ?",selectionArgs);

    }

    public void update(Product product){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put("name",product.name);
        cv.put("qty",product.qty);
        String [] selectionArgs = {""+product.id};
        db.update("msproduct",cv,"id = ?",selectionArgs);
    }
}
