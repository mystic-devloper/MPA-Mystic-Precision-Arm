#ifndef __MYSTIC_PRECISION_ARM_TYPES_H__
#define __MYSTIC_PRECISION_ARM_TYPES_H__

#include <cstdint> // For uint8_t, int32_t, etc.
#include <cstddef> // For size_t, ssize_t

// --- Standard Fixed-Width Type Aliases ---
typedef float    f32;
typedef double   f64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef size_t   usize;  // Standard unsigned size type
typedef ssize_t  isize;  // Standard signed size type (often a typedef for long or int on systems)

// --- Mathematical Constants ---
#define PI 3.14159265358979323846f
#define TAU (2.0f * PI)

#endif // __MYSTIC_PRECISION_ARM_TYPES_H__
