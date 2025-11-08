#ifndef FUR_RENDER_DRAW_H
#define FUR_RENDER_DRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <render/state.h>
#include <core/macros.h>
#include <core/matrix.h>
#include <core/data/texture.h>
#include <core/renderTarget.h>
#include <stdlib.h>
#include <math.h>

/* ====== DATATYPES ====== */

typedef struct {
    FUR_renderTarget* target;
    v3 col;
} OP_fur_render_clear;

/* ====== FUNCS ====== */

void IMPL_fur_render_clear(FUR_renderState* render, OP_fur_render_clear op);

void fur_render_flush(FUR_renderState* render);

/* ====== MACROS ====== */

#define fur_render_clear(render, ...) \
    IMPL_fur_render_clear((render), (OP_fur_render_clear){ .target = render->defTarget, .col = (v3){0,0,0}, __VA_ARGS__ })

/* ====== STRUCTS ====== */

typedef struct {
    FUR_renderTarget* target;
    v2 pos;
    v2 size;
    v4 col;
    mat4* transf;
    mat4* proj;
} OP_fur_render_rect;

typedef struct {
    FUR_renderTarget* target;
    FUR_texture* texture;
    v2 pos;
    v2 size;
    v4 sample;
    v4 col;
    mat4* transf;
    mat4* proj;
} OP_fur_render_tex;

typedef struct {
    FUR_renderTarget* out_target;
    FUR_renderTarget* in_target;
    v2 pos;
    v2 size;
    v4 sample;
    v4 col;
    mat4* transf;
    mat4* proj;
} OP_fur_render_renderTarget;

/* ====== FUNCS ====== */

void IMPL_fur_render_rect(FUR_renderState* render, OP_fur_render_rect op);
void IMPL_fur_render_tex(FUR_renderState* render, OP_fur_render_tex op);
void IMPL_fur_render_renderTarget(FUR_renderState* render, OP_fur_render_renderTarget op);

/* ====== MACROS ====== */

#define fur_render_rect(render, ...) \
    IMPL_fur_render_rect((render), STRUCT_LIT(OP_fur_render_rect){ .target = render->defTarget, .pos = STRUCT_LIT(v2){0,0}, .size = STRUCT_LIT(v2){0,0}, .col = STRUCT_LIT(v4){1,1,1,1}, .transf = mat4_identity_ptr, .proj = NULL, __VA_ARGS__ })

#define fur_render_tex(render, ...) \
    IMPL_fur_render_tex((render), STRUCT_LIT(OP_fur_render_tex){ .target = render->defTarget, .texture = NULL, .pos = STRUCT_LIT(v2){0,0}, .size = STRUCT_LIT(v2){NAN,NAN}, .col = STRUCT_LIT(v4){1,1,1,1}, .transf = mat4_identity_ptr, .proj = NULL, .sample = STRUCT_LIT(v4){NAN,NAN,NAN,NAN}, __VA_ARGS__ })

#define fur_render_renderTarget(render, ...) \
    IMPL_fur_render_renderTarget((render), STRUCT_LIT(OP_fur_render_renderTarget){ .out_target = render->defTarget, .in_target = NULL, .pos = STRUCT_LIT(v2){0,0}, .size = STRUCT_LIT(v2){NAN,NAN}, .col = STRUCT_LIT(v4){1,1,1,1}, .transf = mat4_identity_ptr, .proj = NULL, .sample = STRUCT_LIT(v4){NAN,NAN,NAN,NAN}, __VA_ARGS__ })

#ifdef __cplusplus
}
#endif

#endif
