#ifndef __MYSTIC_PRECISION_ARM_ROUND_H__ // Include guard to prevent multiple inclusions of this header file.
#define __MYSTIC_PRECISION_ARM_ROUND_H__ // Defines the macro to mark this header as included.

#include <mpa/types.h> // Includes the necessary type definitions from the 'mpa' library.

namespace mpa { // Defines the top-level namespace for the Mystic Precision ARM (MPA) library.

namespace round { // Defines a nested namespace specifically for rounding functions.

// Template function for rounding to the nearest integer.
// For example, nearest(2.5) could be 3, a.k.a commercial rounding).
template <typename T> T nearest(T x);

// Template function for rounding towards zero (truncation).
// For example, towards_zero(2.7) would be 2, and towards_zero(-2.7) would be -2.
template <typename T> T towards_zero(T x);

// Template function for rounding away from zero.
// For example, away_from_zero(2.3) would be 3, and away_from_zero(-2.3) would be -3.
template <typename T> T away_from_zero(T x);

// Template function for rounding towards the nearest even integer.
// For example, towards_even(2.5) would be 2, and towards_even(3.5) would be 4.
template <typename T> T towards_even(T x);

// Template function for rounding towards the nearest odd integer.
// For example, towards_odd(2.5) would be 3, and towards_odd(3.5) would be 3.
template <typename T> T towards_odd(T x);

// Template function for ceiling: rounds up to the smallest integer greater than or equal to x.
// For example, ceil(2.3) would be 3, and ceil(2.0) would be 2.
template <typename T> T ceil(T x);

// Template function for floor: rounds down to the largest integer less than or equal to x.
// For example, floor(2.7) would be 2, and floor(2.0) would be 2.
template <typename T> T floor(T x);

} // namespace round

} // namespace mpa

#endif // __MYSTIC_PRECISION_ARM_ROUND_H__ // Ends the include guard.
