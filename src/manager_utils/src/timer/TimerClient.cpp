// Corresponding header
#include "manager_utils/timer/TimerClient.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/TimerManager.h"

void TimerClient::startTimer(int64_t interval, int32_t timerId, TimerType timerType) {
    if (!gTimerManager) {
        return;
    }

    constexpr int32_t minTimerInterval = 20;
    if (interval < minTimerInterval) {
        std::cerr << "In TimerClient::startTimer() timer interval is lower than the minimum."
                  << std::endl;
        return;
    }

    const TimerData tData(interval, interval, timerType, this);
    gTimerManager->startTimer(timerId, tData);
}

void TimerClient::stopTimer(int32_t timerId) {
    if (!gTimerManager) {
        return;
    }

    gTimerManager->stopTimer(timerId);
}

bool TimerClient::isTimerActive(int32_t timerId) const {
    if (!gTimerManager) {
        return false;
    }

    return gTimerManager->isActiveTimerId(timerId);
}
