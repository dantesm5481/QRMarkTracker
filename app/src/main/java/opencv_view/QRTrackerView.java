package opencv_view;

import android.content.Context;
import android.util.Log;


import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.MatOfPoint2f;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.CascadeClassifier;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import opencv_view.BasicOpenCVView.BasicOpenCV;


/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class QRTrackerView extends BasicOpenCV implements CameraBridgeViewBase.CvCameraViewListener {

    private CascadeClassifier cascadeClassifier;
    private Mat grayscaleImage , matCB , matY, matCR , matResult;
//    private Vector<Mat> chennl;//色彩通道
    private ArrayList<Mat> matList;
    private ArrayList<MatOfPoint> contours;
    private MatOfPoint2f setpoly ,getpoly;
//    private Vector<MatOfPoint> poly;

    public QRTrackerView(Context context, int cameraId, Mat grayscaleImage) {
        super(context, cameraId);
        this.grayscaleImage = grayscaleImage;
        this.setCvCameraViewListener(this);//加入監聽事件
        this.enableView();
    }

    @Override
    public void onCameraViewStarted(int width, int height) {


        grayscaleImage = new Mat( height , width , CvType.CV_8UC4);
        matResult = new Mat();
        contours = new ArrayList<MatOfPoint>();

        matList = new ArrayList<Mat>();
        setpoly = new MatOfPoint2f();
        getpoly = new MatOfPoint2f();


    }

    @Override
    public void onCameraViewStopped() {

//        grayscaleImage.release();
//        matResult.release();
//        matCB.release();


    }

    @Override
    public Mat onCameraFrame(Mat mat) {








        return mat;
    }







    //QR Tracker
    public Mat QRTrack(Mat mat){

        Imgproc.cvtColor( mat , grayscaleImage , Imgproc.COLOR_RGB2YCrCb);
        Core.split(grayscaleImage , matList);// 分離色彩通道 Y Cr Cb 分別進入 陣列 0、1、2
        matCB = matList.get(2); //

        //CB通道二值化 ，最大值255
        Imgproc.threshold(matCB , matResult ,144, 255,Imgproc.THRESH_BINARY);  //只取 CB值

        //提取外輪廓
        // todo 待理解  grayscaleImage的用法 ， point()的用法
        //hierarchy 層級
        Imgproc.findContours(matResult, contours, grayscaleImage, Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_NONE);

        for (int i= 0 ; i< contours.size();i++){

            double  eps = (double) contours.size()*0.05;
            contours.get(i).convertTo(setpoly,CvType.CV_32FC2);
            Imgproc.approxPolyDP( setpoly , getpoly , eps , true);

            if (contours.size()== 4){
                Imgproc.drawContours(grayscaleImage ,contours, i ,new Scalar(255));
            }

        }


        return mat;
    }









}