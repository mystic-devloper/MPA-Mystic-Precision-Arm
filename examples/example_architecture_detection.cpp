#include <iostream>
#include <mpa/architecture.h>

int main() {
#if defined(__MPA_ARM_64_BITS_ARMV9__)
  std::cout << "It is a ARMv9 architecture." << std::endl;
#elif defined(__MPA_ARM_64_BITS_ARMV8__)
  std::cout << "It is a ARMv8 architecture." << std::endl;
#elif  defined(__MPA_ARM_32_BITS_ARMV7__)
  std::cout << "It is a ARMv7 architecture." << std::endl;
#else
  std::cout << "It is a non supported MPA architecture." << std::endl;
#endif

  return 0;
}
