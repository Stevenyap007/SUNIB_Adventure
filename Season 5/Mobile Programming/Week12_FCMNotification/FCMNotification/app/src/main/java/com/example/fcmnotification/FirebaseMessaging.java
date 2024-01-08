package com.example.fcmnotification;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.os.Build;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.core.app.NotificationCompat;

import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

public class FirebaseMessaging extends FirebaseMessagingService{
    @Override
    public void onMessageReceived(@NonNull RemoteMessage message) {
        super.onMessageReceived(message);
        Log.d("Notif_Title",message.getNotification().getTitle());
        Log.d("Notif_Pesan",message.getNotification().getBody());

        NotificationCompat.Builder notifBuilder = new NotificationCompat.Builder(this,"Notif Download")
                .setSmallIcon(R.drawable.ic_launcher_foreground)
                .setContentTitle(message.getNotification().getTitle())
                .setContentText(message.getNotification().getBody());
        Notification notification = notifBuilder.build();
        NotificationManager notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
            NotificationChannel channel = new NotificationChannel("Notif Download","Download Notification",NotificationManager.IMPORTANCE_HIGH);
            notificationManager.createNotificationChannel(channel);

        }
        notificationManager.notify(1,notification);
    }

    @Override
    public void onNewToken(@NonNull String token) {
        super.onNewToken(token);
    }
}
