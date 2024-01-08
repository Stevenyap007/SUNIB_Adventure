package com.example.pert3;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.DatePicker;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {
    AutoCompleteTextView hobby;
    Spinner kota;
    static TextView tglLahir;
    String [] namaHobby = {"Menyanyi","Melukis","Menggambar"};
    String [] namaKota = {"Jakarta","Bekasi","Tangerang"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toast.makeText(this, "on Create", Toast.LENGTH_LONG).show();

        tglLahir = findViewById(R.id.txtViewTglLahir);

        hobby = findViewById(R.id.txtHobby);
        ArrayAdapter <String> adapterHobby = new ArrayAdapter<String>(this,android.R.layout.select_dialog_item,namaHobby);
        hobby.setAdapter(adapterHobby);

        kota = findViewById(R.id.txtKota);
        ArrayAdapter <String> adapterKota = new ArrayAdapter<String>(this,android.R.layout.select_dialog_item,namaKota);
        kota.setAdapter(adapterKota);

    }

    @Override
    protected void onStart() {
        super.onStart();
        Toast.makeText(this, "on Start", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onResume() {
        super.onResume();
        Toast.makeText(this, "on Resume", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onPause() {
        super.onPause();
        Toast.makeText(this, "on Pause", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onStop() {
        super.onStop();
        Toast.makeText(this, "on Stop", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Toast.makeText(this, "on Destroy", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Toast.makeText(this, "on Restart", Toast.LENGTH_LONG).show();
    }

    public static class DatePickerFragment extends DialogFragment implements DatePickerDialog.OnDateSetListener{
        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            final Calendar c = Calendar.getInstance();
            int year = c.get(Calendar.YEAR);
            int month = c.get(Calendar.MONTH);
            int day = c.get(Calendar.DAY_OF_MONTH);
            return new DatePickerDialog(getActivity(),this,year,month,day);
        }

        @Override
        public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
            String tahun = ""+view.getYear();
            String bulan = ""+(view.getMonth()+1);
            String hari = ""+view.getDayOfMonth();
            tglLahir.setText(tahun +"-"+bulan+"-"+hari);

        }
    }

    public void pilihTanggal(View view) {
        DialogFragment tgl = new DatePickerFragment();
        tgl.show(getFragmentManager(),"datetimepicker");
    }
}