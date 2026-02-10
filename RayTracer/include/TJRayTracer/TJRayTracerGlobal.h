#pragma once

// Detect Windows
#if defined(_WIN32) || defined(__CYGWIN__)
  #if defined(TJRAYTRACER_BUILD_DLL)
    // Building the DLL
    #define TJRAYTRACER_API __declspec(dllexport)
  #else
    // Using the DLL
    #define TJRAYTRACER_API __declspec(dllimport)
  #endif
#else
  #if __GNUC__ >= 4
    #define TJRAYTRACER_API __attribute__((visibility("default")))
  #else
    #define TJRAYTRACER_API
  #endif
#endif