#ifndef TIME_H
#define TIME_H

// C++ system includes
#include <chrono>

class Time {
public:
    Time& getElapsed();

    int64_t toSeconds() const;
    int64_t toMilliseconds() const;
    int64_t toMicroseconds() const;
    int64_t toNanoseconds() const;

private:
    using SteadyClockTimePoint = std::chrono::time_point<std::chrono::steady_clock>;
    SteadyClockTimePoint _now = std::chrono::steady_clock::now();
    SteadyClockTimePoint _elapsedLastCall;
};

#endif  // !TIME_H
