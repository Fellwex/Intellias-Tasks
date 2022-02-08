#pragma once
#include <chrono>
#include <iostream>
#include <string>

class LogDuration 
{
public:
    explicit LogDuration(const std::string& msg = "")
        : message(msg + ": ")
        , start(std::chrono::steady_clock::now())
    {
    }

    ~LogDuration() 
    {
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start;
        std::cerr << message
            << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
            << " ms" << std::endl;
    }
private:
    std::string message;
    std::chrono::steady_clock::time_point start;
};
