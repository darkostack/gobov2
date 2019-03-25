#include "test_platform.h"

#include <sys/time.h>

bool                 gTestPlatAlarmSet     = false;
uint32_t             gTestPlatAlarmNext    = 0;
testPlatAlarmStop    gTestPlatAlarmStop    = NULL;
testPlatAlarmStartAt gTestPlatAlarmStartAt = NULL;
testPlatAlarmGetNow  gTestPlatAlarmGetNow  = NULL;

void testPlatResetToDefaults(void)
{
    gTestPlatAlarmSet     = false;
    gTestPlatAlarmNext    = 0;
    gTestPlatAlarmStop    = NULL;
    gTestPlatAlarmStartAt = NULL;
    gTestPlatAlarmGetNow  = NULL;
}

go::Instance *testInitInstance(void)
{
    goInstance *instance;

    instance = goInstanceInitSingle();

    return static_cast<go::Instance *>(instance);
}

void testFreeInstance(goInstance *aInstance)
{
    goInstanceFinalize(aInstance);
}

//
// Alarm
//
void goPlatAlarmMilliStop(goInstance *aInstance)
{
    if (gTestPlatAlarmStop)
    {
        gTestPlatAlarmStop(aInstance);
    }
    else
    {
        gTestPlatAlarmSet = false;
    }
}

void goPlatAlarmMilliStartAt(goInstance *aInstance, uint32_t aT0, uint32_t aDt)
{
    if (gTestPlatAlarmStartAt)
    {
        gTestPlatAlarmStartAt(aInstance, aT0, aDt);
    }
    else
    {
        gTestPlatAlarmSet  = true;
        gTestPlatAlarmNext = aT0 + aDt;
    }
}

uint32_t goPlatAlarmMilliGetNow(void)
{
    if (gTestPlatAlarmGetNow)
    {
        return gTestPlatAlarmGetNow();
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (uint32_t)((tv.tv_sec * 1000) + (tv.tv_usec / 1000) + 123456);
    }
}

void goPlatAlarmMicroStop(goInstance *aInstance)
{
    if (gTestPlatAlarmStop)
    {
        gTestPlatAlarmStop(aInstance);
    }
    else
    {
        gTestPlatAlarmSet = false;
    }
}

void goPlatAlarmMicroStartAt(goInstance *aInstance, uint32_t aT0, uint32_t aDt)
{
    if (gTestPlatAlarmStartAt)
    {
        gTestPlatAlarmStartAt(aInstance, aT0, aDt);
    }
    else
    {
        gTestPlatAlarmSet  = true;
        gTestPlatAlarmNext = aT0 + aDt;
    }
}

uint32_t goPlatAlarmMicroGetNow(void)
{
    if (gTestPlatAlarmGetNow)
    {
        return gTestPlatAlarmGetNow();
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (uint32_t)((tv.tv_sec * 1000000) + tv.tv_usec + 123456);
    }
}

//
// Misc
//

void goPlatReset(goInstance *aInstance)
{
    (void)aInstance;
}

goPlatResetReason goPlatGetResetReason(goInstance *aInstance)
{
    (void)aInstance;
    return GO_PLAT_RESET_REASON_POWER_ON;
}

//
// Logging
//
void goPlatLog(goLogLevel, goLogRegion, const char *, ...)
{
}
