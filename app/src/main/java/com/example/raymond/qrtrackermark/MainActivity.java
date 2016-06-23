package com.example.raymond.qrtrackermark;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        IntentAction((Button)this.findViewById(R.id.facedecetor), Activity_FaceDetector.class);
        IntentAction((Button)this.findViewById(R.id.QRTracker), Activity_QRTracker.class);

    }

        public void IntentAction(Button btn , final Class<?> c){

            btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent it  = new Intent(MainActivity.this , c );
                startActivity(it);
            }
        });
    }

}
