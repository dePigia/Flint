#pragma once


#ifdef _WIN32
    #ifdef FLINT_BUILD_DLL
        #define FLINT_API __declspec(dllexport)
    #else
        #define FLINT_API __declspec(dllimport)
    #endif
#else
    #ifdef FLINT_BUILD_DLL
        #define FLINT_API __attribute__((visibility("default")))
    #else
        #define FLINT_API
    #endif
#endif