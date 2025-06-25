// examples/example_function.cpp
#include "mpa/types.h" // Include your types header for f64

namespace mpa {

// Placeholder function used in examples
f64 calculate_something_complex(f64 input) {
  if (input < 0.0) {
    // In library, it will always throw an exception
    // We'll return 0.0 for this example, which example_log.cpp checks.
    return 0.0;
  }

  // A simple arbitrary calculation for demonstration
  f64 result = input * input + 5.0 * input - 2.0;

  return result;
}

} // namespace mpa
