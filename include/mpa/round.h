#ifndef __MYSTIC_PRECISION_ARM_ROUND_H__
#define __MYSTIC_PRECISION_ARM_ROUND_H__

#include <cmath>       // For std::round, std::trunc, std::ceil, std::floor, std::rint, std::fabs, std::fmod
#include <type_traits> // For std::enable_if, std::is_floating_point

#include "mpa/types.h" // For f32, f64

namespace mpa {
namespace round {

/**
 * @brief Rounds a floating-point number to the nearest integer.
 * Halfway cases (e.g., 2.5) round away from zero.
 * Equivalent to std::round.
 * @tparam T A floating-point type (e.g., float, double, long double).
 * @param x The input number.
 * @return The nearest integer value of x.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
nearest(T x);

/**
 * @brief Rounds a floating-point number towards zero (truncation).
 * Equivalent to std::trunc.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The integer value of x closer to zero.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_zero(T x);

/**
 * @brief Rounds a floating-point number away from zero.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The integer value of x further from zero.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
away_from_zero(T x);

/**
 * @brief Rounds a floating-point number to the nearest integer.
 * Halfway cases (e.g., 2.5) round to the nearest even integer.
 * Equivalent to std::rint.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The nearest integer value of x, rounding to even in halfway cases.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_even(T x);

/**
 * @brief Rounds a floating-point number to the nearest integer.
 * Halfway cases (e.g., 2.5, 3.5) round to the nearest odd integer.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The nearest integer value of x, rounding to odd in halfway cases.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_odd(T x);

/**
 * @brief Rounds a floating-point number up to the nearest integer.
 * Equivalent to std::ceil.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The smallest integer value not less than x.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
ceil(T x);

/**
 * @brief Rounds a floating-point number down to the nearest integer.
 * Equivalent to std::floor.
 * @tparam T A floating-point type.
 * @param x The input number.
 * @return The largest integer value not greater than x.
 */
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
floor(T x);

} // namespace round
} // namespace mpa

#endif // __MYSTIC_PRECISION_ARM_ROUND_H__
