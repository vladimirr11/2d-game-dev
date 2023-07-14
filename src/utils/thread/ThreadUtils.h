#ifndef THREADUTILS_H
#define THREADUTILS_H

// C++ system includes
#include <cstdint>

class Threading {
public:
    Threading() = delete;

    static void sleepFor(int64_t microseconds);
};

#endif  // !THREADUTILS_H
