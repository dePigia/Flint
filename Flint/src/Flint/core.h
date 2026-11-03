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


#define FLINT_ENABLE_ASSERTS

#ifdef FLINT_ENABLE_ASSERTS
    #define FLINT_ASSERT(x, ...) { if (!(x)) {FLINT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
    #define FLINT_CORE_ASSERT(x, ...) { if (!(x)) {FLINT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#else
    #define FLINT_ASSERT(x, ...)
    #define FLINT_CORE_ASSERT(x, ...)
#endif

#define BIND_EVENT_FN(x) [this](auto&&... args) -> decltype(auto) { return this->x(std::forward<decltype(args)>(args)...); }

#define BIT(x) (1 << x)