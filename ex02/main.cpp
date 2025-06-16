#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Function.hpp"

void testRandomGeneration() {
  std::cout << "=== Test 1: Random Generation ===" << std::endl;

  // Generate several random objects
  for (int i = 0; i < 5; i++) {
    std::cout << "Generation " << (i + 1) << ": ";
    Base* obj = generate();
    if (obj) {
      delete obj;
    }
  }
  std::cout << std::endl;
}

void testPointerIdentification() {
  std::cout << "=== Test 2: Pointer Identification ===" << std::endl;

  // Create objects of each type
  Base* objA = new A();
  Base* objB = new B();
  Base* objC = new C();

  std::cout << "Testing pointer identification:" << std::endl;
  std::cout << "Object A: ";
  identify(objA);

  std::cout << "Object B: ";
  identify(objB);

  std::cout << "Object C: ";
  identify(objC);

  // Test NULL pointer
  std::cout << "NULL pointer: ";
  identify(static_cast<Base*>(NULL));

  // Clean up
  delete objA;
  delete objB;
  delete objC;
  std::cout << std::endl;
}

void testReferenceIdentification() {
  std::cout << "=== Test 3: Reference Identification ===" << std::endl;

  // Create objects of each type
  A objA;
  B objB;
  C objC;

  std::cout << "Testing reference identification:" << std::endl;
  std::cout << "Object A: ";
  identify(objA);

  std::cout << "Object B: ";
  identify(objB);

  std::cout << "Object C: ";
  identify(objC);
  std::cout << std::endl;
}

void testMixedOperations() {
  std::cout << "=== Test 4: Mixed Operations ===" << std::endl;

  // Generate random objects and identify them
  for (int i = 0; i < 3; i++) {
    std::cout << "Round " << (i + 1) << ":" << std::endl;

    Base* obj = generate();
    if (obj) {
      std::cout << "  Pointer identification: ";
      identify(obj);

      std::cout << "  Reference identification: ";
      identify(*obj);

      delete obj;
    }
    std::cout << std::endl;
  }
}

int main() {
  testRandomGeneration();
  testPointerIdentification();
  testReferenceIdentification();
  testMixedOperations();

  std::cout << "=== All tests completed ===" << std::endl;
  return 0;
}
