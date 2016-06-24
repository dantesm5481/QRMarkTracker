package camera_view;

import android.content.Context;
import android.hardware.Camera;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by Raymond Zorro on 2016/6/24.
 */
public class CameraBackground extends SurfaceView implements SurfaceHolder.Callback,Camera.AutoFocusCallback  {

    SurfaceHolder surfaceHolder;
    Camera camera;


    public void startCameraBackground(){
        surfaceHolder = getHolder();
        surfaceHolder.addCallback(this);
        surfaceHolder.setType(SurfaceHolder.SURFACE_TYPE_NORMAL);
    }
    // 自動對焦
    public void CameraAutoFocus(){
        if (camera != null){camera.autoFocus(this);}
    }

    public CameraBackground(Context context) {
        super(context);
        startCameraBackground();
        CameraAutoFocus();
    }


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        try{
            camera = Camera.open();

            camera.setDisplayOrientation(90);
            camera.setPreviewDisplay(surfaceHolder);
            camera.startPreview();


        }catch (Exception e){e.printStackTrace();}
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

        Camera.Parameters parameters = camera.getParameters();
        parameters.setPreviewSize(height, width);
        camera.setParameters(parameters);

        if(surfaceHolder.getSurface() == null)return;

        try{
            camera.stopPreview();
            camera.setPreviewDisplay(surfaceHolder);
            camera.startPreview();
        }catch (Exception e){e.getMessage();}
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        camera.stopPreview();
        camera.release();
        camera = null;
    }
    @Override
    public void onAutoFocus(boolean success, Camera camera) {

    }
}
