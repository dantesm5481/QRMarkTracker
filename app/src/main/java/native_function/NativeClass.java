package native_function;

/**
 * Created by Raymond Zorro on 16/6/22.
 */
public class NativeClass {

    static {
        System.loadLibrary("MyLibrary");
    }

    public native String getMyString();


}
