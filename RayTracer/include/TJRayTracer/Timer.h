#ifndef TJRAYTRACER_TIMER_H
#define TJRAYTRACER_TIMER_H
#include "TJRayTracerGlobal.h"
#include <chrono>
#include <iostream>
#include <thread>
namespace TJRayTracer {
    struct TJRAYTRACER_API Timer
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> duration;

        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;

            float ms = duration.count() * 1000.0f;
            std::cout << "Timer took " << ms << "ms" << std::endl;
        }
    };

}

#endif//TJRAYTRACER_TIMER_H 