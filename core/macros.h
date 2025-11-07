#ifndef FUR_MACROS_H
#define FUR_MACROS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ====== TYPES ====== */

/* --- INTEGERS --- */
typedef signed char s8;
typedef short       s16;
typedef int         s32;
typedef long long   s64;
/* --- UNSIGNED INTEGERS --- */
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
/* --- FLOATS --- */
typedef float  f32;
typedef double f64;
/* --- BOOLEANS --- */
typedef u8  b8;
typedef u16 b16;
typedef u32 b32;
typedef u64 b64;

/* --- VECTORS --- */
#ifdef __cplusplus
struct v2 {
    union {
        struct { f32 x, y; };
        struct { f32 w, h; };
    };

    v2()                : x(0), y(0)    {}
    v2(f32 s)           : x(s), y(s)    {}
    v2(f32 x_, f32 y_)  : x(x_), y(y_)  {}

    v2 operator+(const v2& b) const { return v2{ x + b.x, y + b.y }; }
    v2 operator-(const v2& b) const { return v2{ x - b.x, y - b.y }; }
    v2 operator*(const v2& b) const { return v2{ x * b.x, y * b.y }; }
    v2 operator/(const v2& b) const { return v2{ x / b.x, y / b.y }; }

    v2 operator+(f32 s) const { return v2{ x + s, y + s }; }
    v2 operator-(f32 s) const { return v2{ x - s, y - s }; }
    v2 operator*(f32 s) const { return v2{ x * s, y * s }; }
    v2 operator/(f32 s) const { return v2{ x / s, y / s }; }

    v2 operator+=(const v2& b) { x += b.x; y += b.y; return *this; }
    v2 operator-=(const v2& b) { x -= b.x; y -= b.y; return *this; }
    v2 operator*=(const v2& b) { x *= b.x; y *= b.y; return *this; }
    v2 operator/=(const v2& b) { x /= b.x; y /= b.y; return *this; }

    v2 operator+=(f32 s) { x += s; y += s; return *this; }
    v2 operator-=(f32 s) { x -= s; y -= s; return *this; }
    v2 operator*=(f32 s) { x *= s; y *= s; return *this; }
    v2 operator/=(f32 s) { x /= s; y /= s; return *this; }

    v2 operator-() const { return v2{ -x, -y }; }

    bool operator==(const v2& b) const { return x == b.x && y == b.y; }
    bool operator!=(const v2& b) const { return x != b.x && y != b.y; }

    friend std::ostream& operator<<(std::ostream& os, const v2& v) {
        return os << '(' << v.x << ", " << v.y << ')';
    }
};
#else
typedef struct { f32 x, y; }       v2;
typedef struct { f32 x, y, z; }    v3;
typedef struct { f32 x, y, z, w; } v4;
#endif

/* ====== ERRORS AND WARNINGS ====== */

#define ERROR(...) do { \
        printf("ERROR! [\"%s\" ln:%d]\n", __FILE__, __LINE__); \
        printf(__VA_ARGS__); \
        exit(1); \
    } while (0)

#define ERROR_IF(cond,...) do { if ((cond)) { ERROR(__VA_ARGS__); } } while(0)

#define WARN(...) do { \
        printf("WARNING! [\"%s\" ln:%d]\n", __FILE__, __LINE__); \
        printf(__VA_ARGS__); \
    } while (0)

#define WARN_IF(cond,...) do { if ((cond)) { WARN(__VA_ARGS__); } } while(0)

#define WARN_RET(val, ...) \
    WARN(__VA_ARGS__); \
    return val

#define WARN_RETVOID(...) \
    WARN(__VA_ARGS__); \
    return

#define WARN_RET_IF(cond, val, ...) do { if ((cond)) { WARN_RET((val), __VA_ARGS__); } } while(0)
#define WARN_RETVOID_IF(cond, ...) do { if ((cond)) { WARN_RETVOID(__VA_ARGS__); } } while(0)

/* ====== MEMORY ====== */

#define TRY_FREE(val) \
    if (!(val)) \
        WARN("cannot free value \"%s\"! (is null)", #val); \
    else \
        free(val)

#define FREE_NULLIFY(val) \
    free(val); \
    val = NULL

#define TRY_FREE_NULLIFY(val) \
    TRY_FREE(val); \
    val = NULL

/* ====== VARIABLE STUFF ====== */

#define NEW(type) \
    malloc(sizeof(type))

/* ====== API SPECIFIERS ====== */

#define crit_def_for(func) default: ERROR("selected api has no support for function \"%s\"!\n", func); break
#define warn_def_for(func) default: WARN ("selected api has no support for function \"%s\"!\n", func); break

/* ====== GENERIAL ====== */

#define DEREF_CAST(type, val) \
    (*((type)(val)))

#define CAST(type, val) \
    ((type)(val))

#define UNUSED(param) \
    (void)(param)

#ifdef __cplusplus
#define STRUCT_LIT(type) \
    type
#else
#define STRUCT_LIT(type) \
    (type)
#endif
    

/* ====== MATH ====== */

#define IS_NAN(val) \
    ((val) != (val))

#ifdef __cplusplus
}
#endif

#endif
