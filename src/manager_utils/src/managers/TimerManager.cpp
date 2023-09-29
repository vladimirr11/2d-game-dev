// Corresponding header
#include "manager_utils/managers/TimerManager.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/timer/TimerClient.h"

TimerManager* gTimerManager = nullptr;

int32_t TimerManager::init() {
    _elapsedTime.getElapsed();
    return EXIT_SUCCESS;
}

void TimerManager::process() {
    removeTimersInternal();

    const int64_t msElapsed = _elapsedTime.getElapsed().toMilliseconds();

    for (auto it = _timersMap.begin(); it != _timersMap.end(); it++) {
        auto& [timerId, timerData] = *it;
        timerData.remainingTime -= msElapsed;
        if (0 > timerData.remainingTime) {
            onTimerTimeout(timerId, timerData);
        }
    }

    removeTimersInternal();
}

void TimerManager::deinit() {}

void TimerManager::startTimer(const int32_t timerId, const TimerData& tData) {
    if (isActiveTimerId(timerId)) {
        std::cerr << "In TimerManager::startTimer() trying to start already existing timer - "
                  << timerId << std::endl;
        return;
    }

    _timersMap.emplace(timerId, tData);
}

void TimerManager::stopTimer(int32_t timerId) {
    if (!isActiveTimerId(timerId)) {
        std::cerr << "In TimerManager::stopTimer() trying to stop already stopped timer - "
                  << timerId << std::endl;
        return;
    }

    _removedTimersSet.insert(timerId);
}

bool TimerManager::isActiveTimerId(int32_t timerId) const {
    return (_removedTimersSet.end() == _removedTimersSet.find(timerId)) &&
           (_timersMap.end() != _timersMap.find(timerId));
}

void TimerManager::onInitEnd() { _elapsedTime.getElapsed(); }

size_t TimerManager::getActiveTimersCount() const { return _timersMap.size(); }

void TimerManager::removeTimersInternal() {
    for (const int32_t timerId : _removedTimersSet) {
        auto mapIt = _timersMap.find(timerId);
        if (mapIt != _timersMap.end()) {
            _timersMap.erase(mapIt);
        }
    }

    _removedTimersSet.clear();
}

void TimerManager::onTimerTimeout(const int32_t timerId, TimerData& tData) {
    if (tData.timerType == TimerType::ONESHOT) {
        _removedTimersSet.insert(timerId);
    }

    tData.timerClient->onTimeout(timerId);
    tData.remainingTime += tData.interval;
}
