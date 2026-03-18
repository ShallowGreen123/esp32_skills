#pragma once
#include "demo_log.h"

#define DEMO_CHECK_TRUE(cond, msg)                 \
    do {                                           \
        if (!(cond)) {                             \
            DEMO_ERROR("CHECK FAIL: %s", msg);     \
            return false;                          \
        }                                          \
    } while (0)
