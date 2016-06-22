package opencv_view.BasicOpenCVView;

import android.content.Context;
import android.util.Log;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;

/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class BasicOpenCV extends JavaCameraView  {


    static {
        if (!OpenCVLoader.initDebug()){
              Log.v("Raymond", "  :" + "OpenCV library is failed");}
        else{ Log.v("Raymond", "  :" + "OpenCV library is ready");}
    }

    public BasicOpenCV(Context context, int cameraId) {
        super(context, cameraId);
    }
    public void LoaderCallBack(){

        BaseLoaderCallback callback = new BaseLoaderCallback(getContext()) {
            @Override
            public void onManagerConnected(int status) {
                switch (status){
                    case LoaderCallbackInterface.SUCCESS:
                        break;
                    default:
                        super.onManagerConnected(status);
                        break;

                }
            }
        };


    }

}
