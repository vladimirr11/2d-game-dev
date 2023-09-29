#ifndef MANAGERBASE_H
#define MANAGERBASE_H

enum { DRAW_MANAGER_IDX, RESOURCE_MANAGER_IDX, TIMER_MANAGER_IDX, MANAGERS_COUNT };

class ManagerBase {
public:
    ManagerBase() = default;

    virtual ~ManagerBase() = default;

    ManagerBase(const ManagerBase& other) = delete;
    ManagerBase(ManagerBase&& other) = delete;
    ManagerBase& operator=(const ManagerBase& other) = delete;
    ManagerBase& operator=(ManagerBase&& other) = delete;

    virtual void process() = 0;
    virtual void deinit() = 0;
};

#endif  // !MANAGERBASE_H
