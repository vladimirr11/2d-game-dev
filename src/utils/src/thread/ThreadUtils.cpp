// Corresponding header
#include "utils/thread/ThreadUtils.h"

// C++ system includes
#include <thread>

void Threading::sleepFor(int64_t microseconds) {
    std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
}
