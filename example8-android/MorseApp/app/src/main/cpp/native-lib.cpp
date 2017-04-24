#include <jni.h>
#include <functional>
#include <memory>
#include <string>

extern "C" {

#include "libmorse.h"

    static int length = 0;
    static std::string morseStr{};
    void on()
    {
        ++length;
    }

    void off()
    {
        if (length > 2)
            morseStr += "-";
        else
            morseStr += ".";
        length = 0;
    }

    void wait()
    {
        if (length)
            ++length;
        else
            morseStr += " ";
    }


    JNIEXPORT jstring JNICALL Java_com_example_morseapp_MainActivity_toMorse(
        JNIEnv* env,
        jobject /* this */,
        jstring input)
    {
        morseStr = "";
        auto str = std::unique_ptr<const char, std::function<void(const char*)>>{
            env->GetStringUTFChars(input, nullptr),
            [&] (const char* utf) { env->ReleaseStringUTFChars(input, utf); }
        };
        morse_str(const_cast<char*>(str.get()));
        return env->NewStringUTF(morseStr.c_str());
    }
}
