#ifndef TEST_PLATFORM_H_
#define TEST_PLATFORM_H_

#include <string.h>

#include <gobo/config.h>
#include <gobo/platform/alarm-milli.h>
#include <gobo/platform/alarm-micro.h>
#include <gobo/platform/logging.h>
#include <gobo/platform/misc.h>
#include <gobo/platform/random.h>

#include "common/code_utils.hpp"
#include "common/instance.hpp"

#include "test_util.h"

//
// Alarm Platform
//
typedef void (*testPlatAlarmStop)(goInstance *);
typedef void (*testPlatAlarmStartAt)(goInstance *, uint32_t, uint32_t);
typedef uint32_t (*testPlatAlarmGetNow)(void);

extern bool                 gTestPlatAlarmSet;
extern uint32_t             gTestPlatAlarmNext;
extern testPlatAlarmStop    gTestPlatAlarmStop;
extern testPlatAlarmStartAt gTestPlatAlarmStartAt;
extern testPlatAlarmGetNow  gTestPlatAlarmGetNow;

go::Instance *testInitInstance(void);
void          testFreeInstance(goInstance *aInstance);

// Reset platform functions to defaults
void testPlatResetToDefaults(void);

#endif // TEST_PLATFORM_H_
