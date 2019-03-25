#include "platform-posix.h"
#include <gobo-core-config.h>
#include <gobo/config.h>

#include <ctype.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <syslog.h>

#include <gobo/platform/logging.h>
#include <gobo/platform/toolchain.h>

#include "utils/code_utils.h"

// Macro to append content to end of the log string.

#define LOG_PRINTF(...)                                                                   \
    charsWritten = snprintf(&logString[offset], sizeof(logString) - offset, __VA_ARGS__); \
    goEXPECT_ACTION(charsWritten >= 0, logString[offset] = 0);                            \
    offset += (unsigned int)charsWritten;                                                 \
    goEXPECT_ACTION(offset < sizeof(logString), logString[sizeof(logString) - 1] = 0)

#if (GOBO_CONFIG_LOG_OUTPUT == GOBO_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED)
GO_TOOL_WEAK void goPlatLog(goLogLevel aLogLevel, goLogRegion aLogRegion, const char *aFormat, ...)
{
    char         logString[512];
    unsigned int offset;
    int          charsWritten;
    va_list      args;

    offset = 0;

    LOG_PRINTF("[%d] ", NODE_ID);

    va_start(args, aFormat);
    charsWritten = vsnprintf(&logString[offset], sizeof(logString) - offset, aFormat, args);
    va_end(args);

    goEXPECT_ACTION(charsWritten >= 0, logString[offset] = 0);

exit:
    syslog(LOG_CRIT, "%s", logString);

    GO_UNUSED_VARIABLE(aLogLevel);
    GO_UNUSED_VARIABLE(aLogRegion);
}

#endif // #if (GOBO_CONFIG_LOG_OUTPUT == GOBO_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED)
