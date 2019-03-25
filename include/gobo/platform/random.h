#ifndef GOBO_PLATFORM_RANDOM_H_
#define GOBO_PLATFORM_RANDOM_H_

#include <stdint.h>

#include <gobo/error.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t goPlatRandomGet(void);

goError goPlatRandomGetTrue(uint8_t *aOutput, uint16_t aOutputLength);

#ifdef __cplusplus
}
#endif

#endif // GOBO_PLATFORM_RANDOM_H_
