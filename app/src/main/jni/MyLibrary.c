//
// Created by Toliya on 2016/6/22.
//

#include 'native_function_NativeClass.h'

JNIEXPORT jstring JNICALL Java_native_1function_NativeClass_getMyString(JNIEnv *env, jobject){

    return (*env).NewStringUTF("Raymond finall Test ");

}