#ifndef THREADUTILS_H
#define THREADUTILS_H

// C++ system includes
#include <cstdint>

struct Threading {
    Threading() = delete;

    static void sleepFor(int64_t microseconds);
};

#endif  // !THREADUTILS_H
