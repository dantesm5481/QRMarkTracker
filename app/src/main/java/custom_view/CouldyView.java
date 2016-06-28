package custom_view;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.example.raymond.qrtrackermark.R;

/**
 * Created by Raymond Zorro on 16/6/27.
 */
public class CouldyView extends RelativeLayout{


    String string;
    ImageView img;
    TextView  txt;

    public CouldyView(Context context) {
        super(context);
        this.string = string;
        content();
    }

    private void content() {

        LayoutInflater inflater = LayoutInflater.from(getContext());
        View view = inflater.inflate(R.layout.view_couldy ,null);
        this.addView(view);


    }


}
