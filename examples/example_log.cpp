#include "mpa/types.h"
#include "mpa/logging.h" // Include this to access mpa::set_log_callback and MPA_LOG macros

// Placeholder function (defined in example_function.cpp)
namespace mpa {
  f64 calculate_something_complex(f64 input); // Forward declaration for example
}

// User's custom logging function (can integrate with spdlog, etc.)
void my_user_custom_logger(mpa::LogLevel level, const char *message, const char *file, int line, const char *func) {
  const char *level_str;
    switch (level) {
    case mpa::LogLevel::Trace: level_str = "UserTRC"; break;
    case mpa::LogLevel::Debug: level_str = "UserDBG"; break;
    case mpa::LogLevel::Info: level_str = "UserINF"; break;
    case mpa::LogLevel::Warning: level_str = "UserWRN"; break;
    case mpa::LogLevel::Error: level_str = "UserERR"; break;
    case mpa::LogLevel::Fatal: level_str = "UserFTL"; break;
  }

  printf("[%s] (%s:%d %s) %s\n", level_str, file, line, func, message);
}

int main() {
  // === User enables logging by setting a callback ===
  mpa::set_log_callback(mpa::default_console_logger);
  // OR: mpa::set_log_callback(my_user_custom_logger); // Uncomment to use your custom logger

  // === User makes logging calls using the new MPA_LOG macros ===

  // Example 1: Call with problematic input
  MPA_LOG_INFO("Attempting calculation with negative input: %.2f", -5.0);
  double result1 = mpa::calculate_something_complex(-5.0);
  if (result1 == 0.0) {
    MPA_LOG_ERROR("Calculation with negative input resulted in error. Output: %.2f", result1);
  }
  printf("Result 1: %f\n", result1);

  // Example 2: Call with valid input
  MPA_LOG_INFO("Starting calculation with valid input: %.2f", 10.0);
  double result2 = mpa::calculate_something_complex(10.0);
  MPA_LOG_DEBUG("Calculation finished. Result: %.17f", result2);
  printf("Result 2: %f\n", result2);

  // Demonstrate using the general MPA_LOG macro for explicit level control
  MPA_LOG(mpa::LogLevel::Warning, "This is a warning using MPA_LOG directly, value: %d", 123);
  MPA_LOG(mpa::LogLevel::Trace, "Very detailed trace point using MPA_LOG, internal state: %s", "some_value");

  // You can still use the specific level macros for brevity
  MPA_LOG_INFO("Another info message using MPA_LOG_INFO.");

  return 0;
}
