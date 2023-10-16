#pragma once

#include <chrono>
#include <string>

template <typename Function>
double timeFunction(Function func()) {
    auto start = std::chrono::high_resolution_clock::now();
    func();  // Call the function to be timed
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}
