// Corresponding header
#include "utils/time/Time.h"

Time& Time::getElapsed() {
    _elapsedLastCall = _now;
    _now = std::chrono::steady_clock::now();
    return *this;
}

int64_t Time::toSeconds() const {
    using sec = std::chrono::seconds;
    return std::chrono::duration_cast<sec>(_now - _elapsedLastCall).count();
}

int64_t Time::toMilliseconds() const {
    using millisec = std::chrono::milliseconds;
    return std::chrono::duration_cast<millisec>(_now - _elapsedLastCall).count();
}

int64_t Time::toMicroseconds() const {
    using microsec = std::chrono::microseconds;
    return std::chrono::duration_cast<microsec>(_now - _elapsedLastCall).count();
}

int64_t Time::toNanoseconds() const {
    using nanosec = std::chrono::nanoseconds;
    return std::chrono::duration_cast<nanosec>(_now - _elapsedLastCall).count();
}
