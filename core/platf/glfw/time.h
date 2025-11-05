#ifndef FUR_PLATFORM_GLFW_TIME_H
#define FUR_PLATFORM_GLFW_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <core/time.h>

/* ====== FUNCS ====== */

void fur_glfw_updateTime(void);
void fur_glfw_updateTimer(FUR_timer* timer);

#ifdef __cplusplus
}
#endif

#endif
