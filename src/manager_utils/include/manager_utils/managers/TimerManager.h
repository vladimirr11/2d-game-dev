#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

// C++ system includes
#include <map>
#include <set>

// Third-party includes

// Own includes
#include "manager_utils/managers/ManagerBase.h"
#include "manager_utils/timer/TimerData.h"
#include "utils/time/Time.h"

class TimerManager : public ManagerBase {
public:
    int32_t init();

    void process() final;
    void deinit() final;

    void startTimer(const int32_t timerId, const TimerData& tData);
    void stopTimer(int32_t timerId);

    bool isActiveTimerId(int32_t timerId) const;

    void onInitEnd();

    size_t getActiveTimersCount() const;

private:
    void removeTimersInternal();

    void onTimerTimeout(const int32_t timerId, TimerData& tData);

private:
    Time _elapsedTime;
    std::map<int32_t, TimerData> _timersMap;
    std::set<int32_t> _removedTimersSet;
};

extern TimerManager* gTimerManager;

#endif  // !TIMERMANAGER_H
