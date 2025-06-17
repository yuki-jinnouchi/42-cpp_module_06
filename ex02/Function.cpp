#include "Function.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <typeinfo>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  // Initialize random seed
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    seeded = true;
  }

  // Generate random number between 0 and 2
  int random = std::rand() % 3;

  switch (random) {
    case 0:
      std::cout << "Generated: A" << std::endl;
      return new A();
    case 1:
      std::cout << "Generated: B" << std::endl;
      return new B();
    case 2:
      std::cout << "Generated: C" << std::endl;
      return new C();
    default:
      return NULL;
  }
}

void identify(Base* p) {
  if (p == NULL) {
    std::cout << "Error: NULL pointer" << std::endl;
    return;
  }

  // Try to cast to each type using dynamic_cast
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p) != NULL) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Unknown type" << std::endl;
  }
}

void identify(Base& p) {
  // Use try-catch with dynamic_cast on references
  // Since we cannot use pointers, we must use exception handling
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (const std::bad_cast&) {
    // Not type A, continue
  }

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (const std::bad_cast&) {
    // Not type B, continue
  }

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (const std::bad_cast&) {
    // Not type C
    std::cout << "Unknown type" << std::endl;
  }
}
