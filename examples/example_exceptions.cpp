#include <iostream>
#include <string>
#include "mpa/exceptions.h"

// Function that might throw an invalid_round_mode exception
void set_rounding_mode(int mode) {
    if (mode < 0 || mode > 3) {
        throw mpa::exception::invalid_round_mode(
            "Attempted to set rounding mode to " + std::to_string(mode) + ". Valid range is 0-3."
        );
    }
    std::cout << "Rounding mode set to: " << mode << std::endl;
}

int main() {
    std::cout << "--- Example 1: Catching Specific Exceptions ---" << std::endl;

    try {
        set_rounding_mode(2); // Valid mode
        set_rounding_mode(5); // This will throw an exception
    }
    catch (const mpa::exception::invalid_round_mode& e) {
        // Catch the most specific MPA logic error
        std::cerr << "Caught mpa::exception::invalid_round_mode: " << e.what() << std::endl;
    }
    catch (const mpa::exception::mpa_logic_error& e) {
        // This block would catch other mpa_logic_error types, if they were thrown
        std::cerr << "Caught generic mpa::exception::mpa_logic_error: " << e.what() << std::endl;
    }
    catch (const mpa::exception::mpa_exception& e) {
        // This block would catch any other MPA-specific exception
        std::cerr << "Caught generic mpa::exception::mpa_exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // Fallback for any standard library exception
        std::cerr << "Caught std::exception: " << e.what() << std::endl;
    }
    std::cout << "\n";
    return 0;
}
