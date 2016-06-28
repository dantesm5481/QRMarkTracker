package qr_scanner;

import android.app.Activity;
import android.os.AsyncTask;

import com.google.zxing.qrcode.QRCodeReader;

/**
 * Created by Raymond Zorro on 16/6/27.
 */
public class QRgenerate extends AsyncTask<Void,Void,Void> {


    Activity activity;
    QRCodeReader reader;

    public QRgenerate(Activity activity) {
        this.activity = activity;

    }


    private void ParsingQRcode(){

        reader = new QRCodeReader();

    }


    public static final String result(String result){return result;}

    @Override
    protected Void doInBackground(Void... params) {
        ParsingQRcode();
        return null;
    }
}
