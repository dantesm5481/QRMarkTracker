package opencv_view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Picture;
import android.util.Log;
import android.widget.ImageView;


import com.example.raymond.qrtrackermark.R;

import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.MatOfPoint2f;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.highgui.Highgui;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.CascadeClassifier;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import opencv_view.BasicOpenCVView.BasicOpenCV;
import qr_scanner.QRHelper;
import qr_scanner.QRgenerate;


/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class QRTrackerView extends BasicOpenCV implements CameraBridgeViewBase.CvCameraViewListener {

    private Mat   matCB , matResult ,colormat;
    private ArrayList<Mat> matList;
    private ArrayList<MatOfPoint> contours  ;

    // final element
    private MatOfPoint temp;
    private MatOfPoint2f approxCurve;
    private int debug = 0;


    public QRTrackerView(Context context, int cameraId) {
        super(context, cameraId);
        this.setCvCameraViewListener(this);//加入監聽事件
        this.enableView();
    }

    @Override
    public void onCameraViewStarted(int width, int height) {

        matResult = new Mat();
        contours = new ArrayList<MatOfPoint>();
        matList = new ArrayList<Mat>();

        //Todo test
        colormat = new Mat();
        temp = new MatOfPoint();
        approxCurve = new MatOfPoint2f();


    }

    @Override
    public void onCameraViewStopped() {

        matResult.release();
        matCB.release();
        colormat.release();
        this.releaseCamera();


    }

    @Override
    public Mat onCameraFrame(Mat mat) {//順序關係  mat > colormat > matCB > matResult

        Imgproc.cvtColor(mat, colormat, Imgproc.COLOR_RGB2YCrCb);
        Core.split(colormat, matList); // 分離色彩通道 Y Cr Cb 分別進入 陣列 0、1、2
        matCB = matList.get(2);
        Imgproc.threshold(matCB, matResult, 144, 255, Imgproc.THRESH_BINARY);  //只取 CB值



        //todo 提取四邊
        Imgproc.findContours(matResult, contours, new Mat(), Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_NONE);
//        pointsize();
        Log.v(" Raymond ",  "   Size :" +String.valueOf( contours.size()));
        SquareContours();


//        SquareContours();
//        Imgproc.Canny(matCB,matResult,80,120);  //邊緣檢測模式



        return mat;
//        return matResult;
    }

    private void pointsize(){
        if (!(contours.size() > 1000 || contours.size() < 150)) {
            Log.v(" Raymond " , "   Size :  "+String.valueOf( contours.size()));
            SquareContours();
        }else{
            Log.v(" Raymond " , "  is not enough Size : "+String.valueOf( contours.size()));
        }
    }

    private void SquareContours() {

            for (int i = 0; i < contours.size(); i++) {
                temp = contours.get(i);
                MatOfPoint2f new_mat = new MatOfPoint2f(temp.toArray());
                int contourSize = (int) temp.total();
                Imgproc.approxPolyDP(new_mat, approxCurve , contourSize * 0.05, true);
                if (approxCurve.total() == 4) { //取得四點
                    if (Imgproc.isContourConvex(temp)) {//判斷是否為多邊形
                        Imgproc.drawContours(matResult, contours, i, new Scalar(0, 255, 0), 8);
                        Log.v(" Raymond ", "  approxCurve || is ContourContex == ture : ");
//                        getMat2Image();
                    }
                }}
    }






    private void getMat2Image(){

        Bitmap bm = Bitmap.createBitmap(matResult.cols(), matResult.rows(),Bitmap.Config.ARGB_8888);
        Utils.matToBitmap(matResult, bm);// Mat convert to Bitmap
        // todo test bitmap  pic from drawable
//        Bitmap bm = BitmapFactory.decodeResource(getContext().getResources(), R.drawable.abc1002);

        try{
            String s = QRHelper.getReult(bm);
            Log.v(" Raymond ","  QRHelp  :"+ s);
        }catch (Exception e){
            Log.v(" Raymond ","  QRHelp Exception :"+"  times"+String.valueOf(debug) +"  :  "+e.getMessage());
        }
    }



    private ImageView setImageViewonMat(){

        ImageView result = new ImageView(getContext());
        return result;
    }
}