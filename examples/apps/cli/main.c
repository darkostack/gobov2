#include <assert.h>
#include <gobo-core-config.h>
#include <gobo/config.h>

#include <gobo/cli.h>
#include <gobo/platform/logging.h>
#include <gobo/tasklet.h>

#include "gobo-system.h"

void goTaskletsSignalPending(goInstance *aInstance)
{
    (void)aInstance;
}

int main(int argc, char *argv[])
{
    goInstance *sInstance;

pseudo_reset:

    goSysInit(argc, argv);

    sInstance = goInstanceInitSingle();

    assert(sInstance);

    goCliUartInit(sInstance);

    while (!goSysPseudoResetWasRequested())
    {
        goTaskletsProcess(sInstance);
        goSysProcessDrivers(sInstance);
    }

    goInstanceFinalize(sInstance);

    goto pseudo_reset;

    return 0;
}

/*
 * Provide, if required an "goPlatLog()" function
 */
#if GOBO_CONFIG_LOG_OUTPUT == GOBO_CONFIG_LOG_OUTPUT_APP
void goPlatLog(goLogLevel aLogLevel, goLogRegion aLogRegion, const char *aFormat, ...)
{
    va_list ap;
    va_start(ap, aFormat);
    goCliPlatLogv(aLogLevel, aLogRegion, aFormat, ap);
    va_end(ap);
}
#endif
