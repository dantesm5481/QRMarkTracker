package opencv_view;

import android.content.Context;
import android.util.Log;


import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.objdetect.CascadeClassifier;

import opencv_view.BasicOpenCVView.BasicOpenCV;


/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class QRTrackerView extends BasicOpenCV implements CameraBridgeViewBase.CvCameraViewListener {

    private CascadeClassifier cascadeClassifier;
    private Mat grayscaleImage;
    private int absoluteFaceSize;
    private int num = 0;


    public QRTrackerView(Context context, int cameraId, Mat grayscaleImage) {
        super(context, cameraId);
        this.grayscaleImage = grayscaleImage;
        this.setCvCameraViewListener(this);//加入監聽事件
        this.enableView();
    }

    @Override
    public void onCameraViewStarted(int width, int height) {
        grayscaleImage = new Mat( height , width , CvType.CV_8UC4);
    }

    @Override
    public void onCameraViewStopped() {

    }

    @Override
    public Mat onCameraFrame(Mat mat) {



        Log.v(" Raymond " , "   MAT : "+" mat"+String.valueOf(num++));

        return mat;
    }

}