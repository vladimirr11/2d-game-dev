#ifndef TIMERCLIENT_H
#define TIMERCLIENT_H

// Own includes
#include "manager_utils/timer/TimerData.h"

class TimerClient {
public:
    virtual ~TimerClient() = default;

    virtual void onTimeout(int32_t timerId) = 0;

    void startTimer(int64_t interval, int32_t timerId, TimerType timerType);
    void stopTimer(int32_t timerId);

    bool isTimerActive(int32_t timerId) const;
};

#endif  // !TIMERCLIENT_H
