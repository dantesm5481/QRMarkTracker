package com.example.raymond.qrtrackermark;

/**
 * Created by dantesm5481 on 16/6/20.
 */
public class BlueTracker {


    static {System.loadLibrary("bluetrackJNI");}
    private native void btnAnalysis_Click();

}
