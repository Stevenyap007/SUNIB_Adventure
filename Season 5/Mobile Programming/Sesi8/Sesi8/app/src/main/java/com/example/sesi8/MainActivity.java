package com.example.sesi8;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    ListView listView;
    TextView statusDownload;
    String [] TXT = {"Bubur Ayam", "Nasi uduk", "Lontong sayur"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        listView = findViewById(R.id.ListView);
        statusDownload = findViewById(R.id.statusDownload);
        ArrayAdapter <String> adapater = new ArrayAdapter<>(this, androidx.appcompat.R.layout.support_simple_spinner_dropdown_item,TXT);
        listView.setAdapter(adapater);
    }

    public void download(View view) {
        DownloadTask downloadTask = new DownloadTask();
        downloadTask.execute(4);
    }

    public class DownloadTask extends AsyncTask<Integer, Integer, Void>{

        @Override
        protected Void doInBackground(Integer... integers) {
            int jumlahFile = integers[0];
            for (int i = 1; i <= jumlahFile ; i++) {
                try {
                    Thread.sleep(3000);
                    publishProgress(i);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);
            int data = values[0];
            statusDownload.setText(String.format("Download %d / 4 files",data));
        }

        @Override
        protected void onPostExecute(Void unused) {
            super.onPostExecute(unused);
            statusDownload.setText("Download Finished");
            NotificationCompat.Builder notifBuilder = new NotificationCompat
                    .Builder(MainActivity.this, "NOTIF")
                    .setSmallIcon(R.drawable.ic_launcher_foreground)
                    .setContentTitle("Notification Finished")
                    .setContentText("Download Finished");
            Notification notification = notifBuilder.build();
            NotificationManager notificationManager =
                    (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

            if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
                NotificationChannel channel = new NotificationChannel(
                        "NOTIF","Download Finished", notificationManager.IMPORTANCE_HIGH);
                notificationManager.createNotificationChannel(channel);
            }
            notificationManager.notify(1,notification);
        }
    }
}