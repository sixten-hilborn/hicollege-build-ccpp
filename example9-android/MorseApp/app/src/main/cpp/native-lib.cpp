#include <jni.h>
#include <string>

extern "C" {
    JNIEXPORT jstring JNICALL Java_com_example_morseapp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */)
    {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT void JNICALL Java_com_example_morseapp_LibMorse_morseStr(
            JNIEnv* env,
            jstring text,
            jobject )
    {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }
}
