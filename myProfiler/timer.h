#pragma once
#include <chrono>
#include <iostream>

class Timer
{
public:
    Timer(const char* funcName) : funcName(funcName)
    {
        tStart = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        auto tEnd = std::chrono::high_resolution_clock::now();
        //
        auto tDur = std::chrono::duration<double, std::milli>(tEnd - tStart);

        std::cout << "function: "<< funcName << " took: " << tDur.count() << "ms" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> tStart;
    const char* funcName;
};

#define TIMER_IMPL(a) Timer timer__FUNCTION__ = Timer(a)

#define TIMER TIMER_IMPL(__FUNCTION__)
