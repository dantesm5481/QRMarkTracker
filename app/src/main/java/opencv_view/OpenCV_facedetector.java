package opencv_view;

import android.content.Context;
import android.util.AttributeSet;
import android.util.Log;

import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Mat;

/**
 * Created by Raymond Zorro on 2016/6/21.
 */
public class OpenCV_facedetector extends JavaCameraView implements CameraBridgeViewBase.CvCameraViewListener{




    static {

        if (!OpenCVLoader.initDebug()){
            Log.v("Raymond","  :"+"NO");
        }
        else{
            Log.v("Raymond","  :"+"YES");
        }
    }

    public OpenCV_facedetector(Context context, AttributeSet attrs) {
        super(context, attrs);
    }


    @Override
    public void onCameraViewStarted(int width, int height) {

    }

    @Override
    public void onCameraViewStopped() {

    }

    @Override
    public Mat onCameraFrame(Mat inputFrame) {
        return null;
    }



}
