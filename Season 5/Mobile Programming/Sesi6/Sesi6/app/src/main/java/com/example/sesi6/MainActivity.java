package com.example.sesi6;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.ActionMode;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    TextView ctx_floating;
    TextView ctx_contextual;
    Button popUpButton;
    ActionMode actionMode;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ctx_floating = findViewById(R.id.ctx_floating);
        ctx_contextual = findViewById(R.id.ctx_contextual);
        popUpButton = findViewById(R.id.popUpButton);
        registerForContextMenu(ctx_floating);

        ctx_contextual.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                actionMode = MainActivity.this.startActionMode(actionCallBack);
                return true;
            }
        });
    }

    public ActionMode.Callback actionCallBack = new ActionMode.Callback() {
        @Override
        public boolean onCreateActionMode(ActionMode mode, Menu menu) {
            getMenuInflater().inflate(R.menu.context_menu,menu);
            return true;
        }

        @Override
        public boolean onPrepareActionMode(ActionMode mode, Menu menu) {
            return false;
        }

        @Override
        public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
            int id = item.getItemId();
            if (id == R.id.edit){
                Toast.makeText(MainActivity.this, "Ini Menu Edit", Toast.LENGTH_SHORT).show();
            }else if (id == R.id.share){
                Toast.makeText(MainActivity.this, "Ini Menu Share", Toast.LENGTH_SHORT).show();
            }else if (id == R.id.delete){
                Toast.makeText(MainActivity.this, "Ini Menu Delete", Toast.LENGTH_SHORT).show();
            }
            return true;
        }

        @Override
        public void onDestroyActionMode(ActionMode mode) {

        }
    };




    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.nav_item,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.setting){
            Toast.makeText(this, "Ini Menu Setting", Toast.LENGTH_SHORT).show();
        }else if (id == R.id.favorite){
            Toast.makeText(this, "Ini Menu Favorite", Toast.LENGTH_SHORT).show();
        }else if (id == R.id.search){
            Toast.makeText(this, "Ini Menu Search", Toast.LENGTH_SHORT).show();
        }else if (id == R.id.logout){
            Toast.makeText(this, "Ini Menu Logout", Toast.LENGTH_SHORT).show();
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
        getMenuInflater().inflate(R.menu.context_menu,menu);
    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.edit){
            Toast.makeText(this, "Ini Menu Edit", Toast.LENGTH_SHORT).show();
        }else if (id == R.id.share){
            Toast.makeText(this, "Ini Menu Share", Toast.LENGTH_SHORT).show();
        }else if (id == R.id.delete){
            Toast.makeText(this, "Ini Menu Delete", Toast.LENGTH_SHORT).show();
        }

        return super.onContextItemSelected(item);
    }

    public void popUpButton(View view) {
        PopupMenu popupMenu = new PopupMenu(this,popUpButton);
        popupMenu.getMenuInflater().inflate(R.menu.context_menu,popupMenu.getMenu());
        popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                int id = item.getItemId();
                if (id == R.id.edit){
                    Toast.makeText(MainActivity.this, "Ini Menu Edit", Toast.LENGTH_SHORT).show();
                }else if (id == R.id.share){
                    Toast.makeText(MainActivity.this, "Ini Menu Share", Toast.LENGTH_SHORT).show();
                }else if (id == R.id.delete){
                    Toast.makeText(MainActivity.this, "Ini Menu Delete", Toast.LENGTH_SHORT).show();
                }
                return true;
            }
        });
        popupMenu.show();
    }
}