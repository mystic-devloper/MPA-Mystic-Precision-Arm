#ifndef __MYSTIC_PRECISION_ARM_ARCHITECTURE_H__
#define __MYSTIC_PRECISION_ARM_ARCHITECTURE_H__

#if defined(__aarch64__) && (__ARM_ARCH >= 9)
  // Defines for 64-bit ARMv9-A and newer
  #define __MPA_ARM_64_BITS_ARMV9__
#elif defined(__aarch64__) && (__ARM_ARCH >= 8)
  // Defines for 64-bit ARMv8-A
  #define __MPA_ARM_64_BITS_ARMV8__
#elif defined(__arm__) && (__ARM_ARCH >= 7) && !defined(__aarch64__)
  // Defines for 32-bit ARMv7-A
  #define __MPA_ARM_32_BITS_ARMV7__
#else
  // Fallback for unknown ARM versions or other architectures
  #define __MPA_ARM_UNKNOWN__
#endif

#endif // __MYSTIC_PRECISION_ARM_ARCHITECTURE_H__
