#ifndef DLLTEST_H
#define DLLTEST_H

//#include "dlltest_global.h"
#include <iostream>
#include <string>

#define EXPORT __declspec(dllexport)

extern "C"
{
    EXPORT void test(void (*a)(const char *))
    {
        std::string str("STD STRING TEST");
        a(str.data());
    }

    EXPORT void hello()
    {
        std::cout << "hello world" << std::endl;
    }
}

#endif // DLLTEST_H
