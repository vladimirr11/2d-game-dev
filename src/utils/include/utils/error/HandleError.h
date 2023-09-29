#ifndef HANDLEERROR_H
#define HANDLEERROR_H

// C++ system includes
#include <cstdint>
#include <iostream>

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define handleError(func)                                                                    \
    ({                                                                                       \
        const int32_t errCode = (func);                                                      \
        if (errCode != EXIT_SUCCESS) {                                                       \
            std::cerr << "Runtime error occurred: " << #func << " returned EXIT_FAILURE at " \
                      << __FILE__ << ", line " << __LINE__ << "\n";                          \
            return errCode;                                                                  \
        }                                                                                    \
    })
#else
#define handleError(func) (func)
#endif

#endif  // !HANDLEERROR_H
