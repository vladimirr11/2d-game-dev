// Corresponding header
#include "manager_utils/managers/ResourceManager.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/config/ResourceManagerCfg.h"
#include "utils/error/HandleError.h"

ResourceManager* gResourceManager = nullptr;

int32_t ResourceManager::init(const ResourceManagerConfig& resourceMgrCfg) {
    handleError(ImageContainer::init(resourceMgrCfg.imageContainerCfg));
    handleError(TextContainer::init(resourceMgrCfg.textContainerCfg));
    return EXIT_SUCCESS;
}

void ResourceManager::deinit() {
    TextContainer::deinit();
    ImageContainer::deinit();
}

void ResourceManager::process() {}
