#include "platform-posix.h"

#include <unistd.h>

#include <gobo/platform/misc.h>

#include "gobo-system.h"

extern int    gArgumentsCount;
extern char **gArguments;

static goPlatResetReason   sPlatResetReason = GO_PLAT_RESET_REASON_POWER_ON;
bool                       gPlatformPseudoResetWasRequested;
static goPlatMcuPowerState gPlatMcuPowerState = GO_PLAT_MCU_POWER_STATE_ON;

void goPlatReset(goInstance *aInstance)
{
#if GOBO_PLATFORM_USE_PSEUDO_RESET
    gPlatformPseudoResetWasRequested = true;
    sPlatResetReason                 = GO_PLAT_RESET_REASON_SOFTWARE;
#else

    char *argv[gArgumentsCount + 1];

    for (int i = 0; i < gArgumentsCount; ++i)
    {
        argv[i] = gArguments[i];
    }

    argv[gArgumentsCount] = NULL;

    goSysDeInit();
    platformUartRestore();

    alarm(0);

    execvp(argv[0], argv);
    perror("reset failed");
    exit(EXIT_FAILURE);
#endif

    GO_UNUSED_VARIABLE(aInstance);
}

goPlatResetReason goPlatGetResetReason(goInstance *aInstance)
{
    GO_UNUSED_VARIABLE(aInstance);

    return sPlatResetReason;
}

void goPlatWakeHost(void)
{
    // TODO: implement an operation to wake the host from sleep state.
}

goError goPlatSetMcuPowerState(goInstance *aInstance, goPlatMcuPowerState aState)
{
    goError error = GO_ERROR_NONE;

    GO_UNUSED_VARIABLE(aInstance);

    switch (aState)
    {
    case GO_PLAT_MCU_POWER_STATE_ON:
    case GO_PLAT_MCU_POWER_STATE_LOW_POWER:
        gPlatMcuPowerState = aState;
        break;

    default:
        error = GO_ERROR_FAILED;
        break;
    }

    return error;
}

goPlatMcuPowerState goPlatGetMcuPowerState(goInstance *aInstance)
{
    GO_UNUSED_VARIABLE(aInstance);

    return gPlatMcuPowerState;
}
