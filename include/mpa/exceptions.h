#ifndef __MYSTIC_PRECISION_ARM_EXCEPTIONS_H__
#define __MYSTIC_PRECISION_ARM_EXCEPTIONS_H__

#include <stdexcept> // For std::exception, std::runtime_error, std::logic_error
#include <string>    // For std::string
#include <utility>   // For std::move

namespace mpa {

namespace exception {

// Base class for all MPA-specific exceptions.
// Inherits from std::exception, allowing a single catch point for all MPA errors.
class mpa_exception : public std::exception {
private:
  std::string _message;

public:
  explicit mpa_exception(std::string message) noexcept
    : _message(std::move(message)) {}

  // Returns the full error message.
  const char* what() const noexcept override {
    return _message.c_str();
  }

  // Virtual destructor for proper polymorphic cleanup.
  virtual ~mpa_exception() noexcept = default;
};

// Base class for MPA runtime errors.
// Inherits from both mpa_exception and std::runtime_error.
class mpa_runtime_error : public mpa_exception, public std::runtime_error {
public:
  explicit mpa_runtime_error(const std::string& message)
    : mpa_exception("MPA Runtime Error: " + message),
      std::runtime_error("MPA Runtime Error: " + message) {}
  
  const char* what() const noexcept override {
      return mpa_exception::what();
  }
};

// Base class for MPA logic errors.
// Inherits from both mpa_exception and std::logic_error.
class mpa_logic_error : public mpa_exception, public std::logic_error {
public:
  explicit mpa_logic_error(const std::string& message)
    : mpa_exception("MPA Logic Error: " + message),
      std::logic_error("MPA Logic Error: " + message) {}

  const char* what() const noexcept override {
      return mpa_exception::what();
  }
};

// Specific exception for invalid rounding mode issues.
class invalid_round_mode : public mpa_logic_error  {
public:
  explicit invalid_round_mode(const std::string& message)
    : mpa_logic_error("Invalid Round Mode: " + message) {}
};

// Specific exception for resource not found issues.
class resource_not_found : public mpa_runtime_error {
public:
  explicit resource_not_found(const std::string& message)
    : mpa_runtime_error("Resource Not Found: " + message) {}
};

} // namespace exception

} // namespace mpa

#endif // __MYSTIC_PRECISION_ARM_EXCEPTIONS_H__
