// Corresponding header
#include "manager_utils/managers/ManagerHandler.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/DrawManager.h"
#include "manager_utils/managers/ResourceManager.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

int32_t ManagerHandler::init(const ManagerHandlerCfg& managerHandlerCfg) {
    gDrawMgr = new DrawManager();
    if (gDrawMgr == nullptr) {
        std::cerr << "Error, bad allocation for DrawManager!" << std::endl;
        return EXIT_FAILURE;
    }

    if (gDrawMgr->init(managerHandlerCfg.drawManagerCfg) != EXIT_SUCCESS) {
        std::cerr << "gDrawMgr->init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    gResourceMgr = new ResourceManager();
    if (gResourceMgr == nullptr) {
        std::cerr << "Error, bad allocation for ResourceManager!" << std::endl;
        return EXIT_FAILURE;
    }

    if (gResourceMgr->init(managerHandlerCfg.resourceManagerCfg) != EXIT_SUCCESS) {
        std::cerr << "gResourceMgr->init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    _managers[DRAW_MANAGER_IDX] = static_cast<ManagerBase*>(gDrawMgr);
    _managers[RESOURCE_MANAGER_IDX] = static_cast<ManagerBase*>(gResourceMgr);

    return EXIT_SUCCESS;
}

void ManagerHandler::deinit() {
    for (int32_t i = MANAGERS_COUNT - 1; i >= 0; i--) {
        _managers[i]->deinit();
        _managers[i] = nullptr;
        nullifyGlobalManager(i);
    }
}

void ManagerHandler::process() {
    for (int32_t i = 0; i < MANAGERS_COUNT; i++) {
        _managers[i]->process();
    }
}

void ManagerHandler::nullifyGlobalManager(int32_t managerIdx) {
    switch (managerIdx) {
    case DRAW_MANAGER_IDX:
        delete gDrawMgr;
        gDrawMgr = nullptr;
        break;
    case RESOURCE_MANAGER_IDX:
        delete gResourceMgr;
        gResourceMgr = nullptr;
        break;
    default:
        std::cerr << "Recieved invalid managerIndx!" << std::endl;
        break;
    }
}
