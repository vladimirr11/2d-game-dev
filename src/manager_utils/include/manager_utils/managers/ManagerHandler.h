#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H

// C++ system includes
#include <cstdint>

// Own includes
#include "manager_utils/managers/ManagerBase.h"

// Forward declarations
struct ManagerHandlerCfg;

class ManagerHandler {
public:
    int32_t init(const ManagerHandlerCfg& managerHandlerCfg);
    void deinit();
    void process();

private:
    void nullifyGlobalManager(int32_t managerIdx);

private:
    ManagerBase* _managers[MANAGERS_COUNT];
};

#endif  // !MANAGERHANDLER_H
