package com.example.latihan;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
public class ProductAdapter  extends RecyclerView.Adapter <ProductAdapter.ViewHolder>{
    Context context;
    ArrayList<Product> listProduct;

    public ProductAdapter(Context context){
        this.context = context;
        this.listProduct = new ArrayList<>();
    }
    public  void  setListProduct(ArrayList<Product> listProduct){
        this.listProduct = listProduct;
        notifyDataSetChanged();
    }
    @NonNull
    @Override
    public ProductAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.item_rv,parent,false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ProductAdapter.ViewHolder holder, int position) {
        Product msProduct = listProduct.get(position);

        int id = msProduct.id;
        String name = msProduct.name;
        int qty = msProduct.qty;

        holder.content.setText(msProduct.id +" "+msProduct.name +" "+msProduct.qty);

    }

    @Override
    public int getItemCount() {
        return listProduct.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        TextView content;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);

            content = itemView.findViewById(R.id.content);
            itemView.setOnClickListener(this);
        }

        @Override
        public void onClick(View v) {

            PopupMenu popupMenu = new PopupMenu(context,v);
            popupMenu.getMenuInflater().inflate(R.menu.menu,popupMenu.getMenu());

            popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                @Override
                public boolean onMenuItemClick(MenuItem item) {
                    MsFunction productFunction;
                    int position = getAdapterPosition();
                    Product product = listProduct.get(position);
                    Intent i = new Intent(context, UpdateActivity.class);
                    switch (item.getItemId())
                    {
                        case R.id.menu_edit:
                            i.putExtra("idProduct",product.id+"");
                            i.putExtra("name",product.name+"");
                            i.putExtra("qty",product.qty+"");
                            context.startActivity(i);
                            return true;
                        case R.id.menu_delete:
                            productFunction = new MsFunction(context);
                            productFunction.deleteProduct(product.id);
                            ViewFragment.adapter.setListProduct(productFunction.getAllProduct());
                            return true;

                    }
                    return false;
                }
            });
            popupMenu.show();
        }


    }
}
