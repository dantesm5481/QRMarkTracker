package com.example.raymond.qrtrackermark;
import android.os.Bundle;
import com.example.raymond.qrtrackermark.basic_view_activity.BasicActivity;
import org.opencv.core.Mat;
import opencv_view.FaceDetectorView;

/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class Activity_FaceDetector extends BasicActivity {

    FaceDetectorView facedetectorView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        facedetectorView  = new FaceDetectorView(this, -1 , new Mat());
        setContentView(facedetectorView);

    }




}
