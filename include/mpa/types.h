#ifndef __MYSTIC_PRECISION_ARM_TYPES_H__
#define __MYSTIC_PRECISION_ARM_TYPES_H__

#include <cstdint> // For uint8_t, int32_t, etc.
#include <cstddef> // For size_t, ssize_t

// --- MPA Namespace ---
namespace mpa {

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
constexpr f32 PI_F32 = 3.14159265358979323846F; // More precision for float
constexpr f64 PI_F64 = 3.14159265358979323846;  // Full double precision

constexpr f32 TAU_F32 = (2.0f * PI_F32);
constexpr f64 TAU_F64 = (2.0 * PI_F64);

// Euler's number (e)
constexpr f32 E_F32 = 2.71828182845904523536F;
constexpr f64 E_F64 = 2.71828182845904523536;

// Common SQRTs
constexpr f64 SQRT2_F64 = 1.41421356237309504880;
constexpr f64 INV_SQRT_F64 = 0.70710678118654752440;
constexpr f64 SQRT3_F64 = 1.73205080756887729353;
constexpr f64 SQRT_PI_F64 = 1.77245385090551599275;
constexpr f64 SQRT5_F64 = 2.23606797749978969641;

// Natural Logrithms
constexpr f64 LN2_F64 = 0.69314718055994530942;
constexpr f64 LN10_F64 = 2.30258509299404568402;

// Golden Ratio
constexpr f64 GOLDEN_RATIO_F64 = 1.61803398874989484820;

} // namespace mpa

#endif // __MYSTIC_PRECISION_ARM_TYPES_H__
