#include <cmath> // For std::round, std::trunc, std::ceil, std::floor, std::rint, std::fabs, std::fmod
#include <type_traits> // For std::enable_if, std::is_floating_point

#include "mpa/types.h" // For f32, f64
#include "mpa/round.h" // Function definations

namespace mpa {

namespace round {

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
nearest(T x) {
    return std::round(x);
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_zero(T x) {
    return std::trunc(x);
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
away_from_zero(T x) {
    if (x >= static_cast<T>(0.0)) {
        return std::ceil(x);
    } else {
        return std::floor(x);
    }
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_even(T x) {
    return std::rint(x);
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
towards_odd(T x) {
    T rounded_x = std::round(x);
    if (std::fabs(x - rounded_x) == static_cast<T>(0.5)) {
        if (static_cast<long long>(rounded_x) % 2 == 0) {
            return (x > static_cast<T>(0)) ? rounded_x - static_cast<T>(1.0) : rounded_x + static_cast<T>(1.0);
        }
    }
    return rounded_x;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
ceil(T x) {
    return std::ceil(x);
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
floor(T x) {
    return std::floor(x);
}

// Explicitly instantiate for f32 (float)
template f32 nearest<f32>(f32);
template f32 towards_zero<f32>(f32);
template f32 away_from_zero<f32>(f32);
template f32 towards_even<f32>(f32);
template f32 towards_odd<f32>(f32);
template f32 ceil<f32>(f32);
template f32 floor<f32>(f32);

// Explicitly instantiate for f64 (double)
template f64 nearest<f64>(f64);
template f64 towards_zero<f64>(f64);
template f64 away_from_zero<f64>(f64);
template f64 towards_even<f64>(f64);
template f64 towards_odd<f64>(f64);
template f64 ceil<f64>(f64);
template f64 floor<f64>(f64);

} // namespace mpa

} // namespace round
