package com.example.raymond.qrtrackermark;

import android.os.Bundle;
import android.widget.Toast;

import com.example.raymond.qrtrackermark.basic_view_activity.BasicActivity;

import org.opencv.core.Mat;

import opencv_view.MarkerViewrToQR;
import opencv_view.QRTrackerView;

/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class Activity_QRTracker extends BasicActivity{


    QRTrackerView trackerView;
    MarkerViewrToQR markerView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        try {

            trackerView = new QRTrackerView(this, -1);
            markerView = new MarkerViewrToQR(this,-1);
            setContentView(markerView);

            Toast.makeText(this ,"成功進入 openCV Camera",Toast.LENGTH_LONG).show();


        }catch (Exception e){

            Toast.makeText(this , e.getMessage(),Toast.LENGTH_LONG).show();
        }
    }






}
