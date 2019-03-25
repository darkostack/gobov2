#include <assert.h>
#include <stdio.h>

#include "platform-posix.h"

#include <gobo/platform/random.h>

#include "utils/code_utils.h"

static uint32_t sState = 1;

void platformRandomInit(void)
{
    sState = (uint32_t)time(NULL) + (3600 * NODE_ID);
}

uint32_t goPlatRandomGet(void)
{
    uint32_t mlcg, p, q;
    uint64_t tmpstate;

    tmpstate = (uint64_t)33614 * (uint64_t)sState;
    q        = tmpstate & 0xffffffff;
    q        = q >> 1;
    p        = tmpstate >> 32;
    mlcg     = p + q;

    if (mlcg & 0x80000000)
    {
        mlcg &= 0x7fffffff;
        mlcg++;
    }

    sState = mlcg;

    return mlcg;
}

goError goPlatRandomGetTrue(uint8_t *aOutput, uint16_t aOutputLength)
{
    goError error = GO_ERROR_NONE;

    goEXPECT_ACTION(aOutput && aOutputLength, error = GO_ERROR_INVALID_ARGS);

    for (uint16_t length = 0; length < aOutputLength; length++)
    {
        aOutput[length] = (uint8_t)goPlatRandomGet();
    }

exit:
    return error;
}
