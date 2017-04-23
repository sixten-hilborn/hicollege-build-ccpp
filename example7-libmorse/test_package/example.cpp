#include <iostream>

extern "C" {
#include "libmorse.h"

    static int length = 0;
    void on()
    {
        ++length;
    }

    void off()
    {
        if (length > 2)
            std::cout << "-";
        else
            std::cout << ".";
        length = 0;
    }

    void wait()
    {
        if (length)
            ++length;
        else
            std::cout << " ";
    }
}

int main()
{
    char str[] = "hello world";
    morse_str(str);
    std::cout << std::endl;
}
