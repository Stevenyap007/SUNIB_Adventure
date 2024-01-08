package com.example.latihan;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
public class MsFunction {
    DBHelper dbHelper;

    public  MsFunction (Context context){
        dbHelper = new DBHelper(context,"latihan",null,1);
    }

    public void insertProduct(Product product){
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        ContentValues cv = new ContentValues();
        cv.put("name", product.name);
        cv.put("qty", product.qty);

        db.insert("msproduct", null, cv);
        db.close();
    }

    public ArrayList<Product> getAllProduct() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        ArrayList<Product> listProduct = new ArrayList<>();
        ;
        Cursor cursor = db.rawQuery("select * from msproduct", null);
        Product product = null;
        while (cursor.moveToNext()) {
            // read data
            product = new Product();

            product.id = cursor.getInt(cursor.getColumnIndex("id"));
            product.name = cursor.getString(cursor.getColumnIndex("name"));
            product.qty = cursor.getInt(cursor.getColumnIndex("qty"));
            listProduct.add(product);
        }
        return  listProduct;
    }

    public void updateProduct(Product product){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put("name", product.name );
        cv.put("qty", product.qty );
        String[] selectionArgs = {""+product.id};
        db.update("msproduct",cv,"id = ?",selectionArgs);
    }

    public void deleteProduct(int id){
        String[] selectionArgs = {""+id};
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        db.delete("msproduct","id = ?",selectionArgs);

    }
}
