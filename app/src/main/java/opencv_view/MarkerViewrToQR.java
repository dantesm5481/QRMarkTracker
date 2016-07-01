package opencv_view;
import android.content.Context;
import android.util.Log;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.MatOfPoint2f;
import org.opencv.core.Point;
import org.opencv.imgproc.Imgproc;
import org.opencv.utils.Converters;
import java.util.ArrayList;
import java.util.List;

import opencv_view.BasicOpenCVView.BasicOpenCV;


/**
 * Created by Raymond Zorro on 16/6/30.
 */
public class MarkerViewrToQR extends BasicOpenCV implements CameraBridgeViewBase.CvCameraViewListener{

    private Mat matCB , matColor , matResult , matSrc , matDst;
    private ArrayList<Mat> matList;
    private ArrayList<MatOfPoint> allcontours;
    private MatOfPoint2f approxCurve;
    private MatOfPoint2f Marker;

    private List<Point> dstPoints;

    @Override
    public void onCameraViewStarted(int width, int height) {
    // get Cb mat
    matCB = new Mat();
    matColor = new Mat();
    matResult = new Mat();
    //get perspective mat


    matList = new ArrayList<Mat>();
    allcontours = new ArrayList<MatOfPoint>();
    approxCurve = new MatOfPoint2f();
    Marker = new MatOfPoint2f();

        dstPoints = new ArrayList<Point>(4);
        dstPoints.add(new Point(0,0));
        dstPoints.add(new Point(0,79));
        dstPoints.add(new Point(79,79));
        dstPoints.add(new Point(79,0));

    }



    @Override
    public Mat onCameraFrame(Mat mat) {

        Imgproc.cvtColor(mat, matColor, Imgproc.COLOR_RGB2YCrCb);
        Core.split(matColor, matList);
        matColor.release(); // release memory
        matCB = matList.get(2);
        Imgproc.threshold(matCB, matResult, 129, 255, Imgproc.THRESH_BINARY);
        matCB.release(); // release memory
        // allcontours = MatOfPoint
        Imgproc.findContours(matResult, allcontours, new Mat(), Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_NONE);

        Log.v(" Raymond ", "   size :  "+String.valueOf( allcontours.size()));

        for (int i = 0; i < allcontours.size() ; i++){

            int contoursize  = (int)allcontours.get(i).total();
            MatOfPoint2f matArray = new MatOfPoint2f(allcontours.get(i).toArray());
            Imgproc.approxPolyDP( matArray , approxCurve ,contoursize*0.10 ,true);

            if (approxCurve.total() == 4){ // approxCube  =  MatOfPoint2f
                if (Imgproc.isContourConvex(allcontours.get(i))){

                    matSrc = Converters.vector_Point_to_Mat( allcontours.get(i).toList());
                    matDst = Converters.vector_Point_to_Mat( dstPoints );
                    Mat finalMat = new Mat();

                    Mat m = Imgproc.getPerspectiveTransform(matSrc ,matDst);
//                    Imgproc.warpPerspective();


                }}
        }

        return mat;
    }


    private void scanQRcode(){

//        Bitmap bm =
//        String s = QRHelper.getReult(bm);

    }



    @Override
    public void onCameraViewStopped() {
        matCB.release();
        matColor.release();
        matResult.release();
        this.releaseCamera();
    }

    public MarkerViewrToQR(Context context, int cameraId) {super(context, cameraId);this.setCvCameraViewListener(this);}

}
