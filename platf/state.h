#ifndef FUR_PLATFORM_STATE_H
#define FUR_PLATFORM_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <core/macros.h>

/* ====== DATATYPES ====== */

typedef void FUR_target_platfState;

typedef enum {
    FUR_PLATF_GLFW
} FUR_targetPlatf;

typedef struct {
    FUR_target_platfState* spec;
    FUR_targetPlatf plat;

    char* title;
    s32 width, height;
} FUR_platfState;

#ifdef __cplusplus
}
#endif

#endif
