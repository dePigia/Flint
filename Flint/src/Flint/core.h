#pragma once


#if defined(_WIN32)
    #define FLINT_PLATFORM_WINDOWS
    #ifdef FLINT_BUILD_DLL
        #define FLINT_API __declspec(dllexport)
    #else
        #define FLINT_API __declspec(dllimport)
    #endif
#elif defined(__linux__)
    #define FLINT_PLATFORM_LINUX
    #ifdef FLINT_BUILD_DLL
        #define FLINT_API __attribute__((visibility("default")))
    #else
        #define FLINT_API
    #endif
#else
    #error "Platform not supported!"
#endif


#define BIT(x) (1 << x)