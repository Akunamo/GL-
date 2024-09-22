#pragma once

#ifdef _WIN32
    #ifdef DK_BUILD_DLL
        #define DUKE_API __declspec(dllexport)
    #else
        #define DUKE_API __declspec(dllimport)
    #endif
#else
    #define DUKE_API __attribute__((visibility("default")))
#endif

#define BIT(x) (1 << x)

#include <cassert>

#define ASSERT(x) assert(x)