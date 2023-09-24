// Corresponding header
#include "manager_utils/managers/ResourceManager.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/config/ResourceManagerCfg.h"

ResourceManager* gResourceMgr = nullptr;

int32_t ResourceManager::init(const ResourceManagerConfig& drawMgrCfg) {
    if (ImageContainer::init(drawMgrCfg.imageContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "ImageContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (TextContainer::init(drawMgrCfg.textContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "TextContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void ResourceManager::deinit() {
    TextContainer::deinit();
    ImageContainer::deinit();
}

void ResourceManager::process() {}
