package com.example.raymond.qrtrackermark;

import android.os.Bundle;

import com.example.raymond.qrtrackermark.basic_view_activity.BasicActivity;

import org.opencv.core.Mat;

import opencv_view.QRTrackerView;

/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class Activity_QRTracker extends BasicActivity{


    QRTrackerView trackerView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        trackerView = new QRTrackerView(this, -1 ,new Mat());
        setContentView(trackerView);
    }






}
