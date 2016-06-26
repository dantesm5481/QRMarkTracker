package com.example.raymond.qrtrackermark;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.example.raymond.qrtrackermark.basic_view_activity.BasicActivity;

import camera_view.CameraBackground;
import opencv_view.QRTrackerView;

public class MainActivity extends BasicActivity {


    QRTrackerView qr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);



//        try {
//            IntentAction((Button)this.findViewById(R.id.facedecetor), Activity_FaceDetector.class);
//            IntentAction((Button)this.findViewById(R.id.QRTracker), Activity_QRTracker.class);
//
//            Toast.makeText(this , "成功跳頁",Toast.LENGTH_LONG).show();
//        }catch (Exception e){
//
//            Toast.makeText(this , "開啟失敗"+ e.getMessage(),Toast.LENGTH_LONG).show();
//
//        }


        try {
            autoIntent(Activity_QRTracker.class);
            Toast.makeText(this , "成功跳頁",Toast.LENGTH_LONG).show();
        }catch (Exception e){
            Toast.makeText(this , e.getMessage(),Toast.LENGTH_LONG).show();
        }

    }

        public void IntentAction(Button btn , final Class<?> c){

            btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent it  = new Intent(MainActivity.this , c );
                startActivity(it);
            }
        });
    }

        private void autoIntent(final Class<?> c){

            Intent it  = new Intent(MainActivity.this , c);
            startActivity(it);

        }














}
