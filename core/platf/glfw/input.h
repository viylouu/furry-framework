#ifndef FUR_PLATFORM_GLFW_INPUT_H
#define FUR_PLATFORM_GLFW_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <platf/glfw/main.h>

/* ====== FUNCS ====== */

void fur_input_glfw_poll(FUR_glfw_platfState* platf);

#ifdef __cplusplus
}
#endif

#endif
