#include <iostream>

#include "Serializer.hpp"

void testBasicSerialization() {
  std::cout << "=== Test 1: Basic Serialization ===" << std::endl;

  // Create a Data object
  Data original;
  original.id = 42;
  original.name = "Test Data";
  original.value = 3.14159;

  // Print the original data
  std::cout << "Original Data object:" << std::endl;
  std::cout << "Address: " << &original << std::endl;
  std::cout << "ID: " << original.id << std::endl;
  std::cout << "Name: " << original.name << std::endl;
  std::cout << "Value: " << original.value << std::endl;
  std::cout << std::endl;

  // Serialize the pointer
  uintptr_t serialized = Serializer::serialize(&original);
  std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
  std::cout << std::endl;

  // Deserialize back to pointer
  Data* deserialized = Serializer::deserialize(serialized);

  // Print the deserialized data
  std::cout << "Deserialized Data object:" << std::endl;
  std::cout << "Address: " << deserialized << std::endl;
  std::cout << "ID: " << deserialized->id << std::endl;
  std::cout << "Name: " << deserialized->name << std::endl;
  std::cout << "Value: " << deserialized->value << std::endl;
  std::cout << std::endl;

  // Check if the pointers are equal
  std::cout << "Pointer comparison: " << std::endl;
  std::cout << "Original:    " << &original << std::endl;
  std::cout << "Deserialized: " << deserialized << std::endl;
  if (&original == deserialized) {
    std::cout << "SUCCESS: Pointers are identical!" << std::endl;
  } else {
    std::cout << "ERROR: Pointers don't match!" << std::endl;
  }
  std::cout << std::endl;
}

// void testMultipleObjects() {
//   std::cout << "=== Test 2: Multiple Objects ===" << std::endl;

//   // Create multiple Data objects
//   Data data1 = {1, "First", 1.1};
//   Data data2 = {2, "Second", 2.2};
//   Data data3 = {3, "Third", 3.3};

//   // Test each object
//   Data* objects[] = {&data1, &data2, &data3};
//   for (int i = 0; i < 3; i++) {
//     std::cout << "Testing object " << (i + 1) << ":" << std::endl;
//     std::cout << "Original address: " << objects[i] << std::endl;

//     uintptr_t serialized = Serializer::serialize(objects[i]);
//     Data* deserialized = Serializer::deserialize(serialized);

//     std::cout << "Deserialized address: " << deserialized << std::endl;
//     std::cout << "Match: " << (objects[i] == deserialized ? "YES" : "NO")
//               << std::endl;
//     std::cout << "Data: {" << deserialized->id << ", \"" <<
//     deserialized->name
//               << "\", " << deserialized->value << "}" << std::endl;
//     std::cout << std::endl;
//   }
// }

// void testNullPointer() {
//   std::cout << "=== Test 3: NULL Pointer ===" << std::endl;

//   Data* nullPtr = NULL;
//   std::cout << "Original NULL pointer: " << nullPtr << std::endl;

//   uintptr_t serialized = Serializer::serialize(nullPtr);
//   std::cout << "Serialized NULL: " << serialized << std::endl;

//   Data* deserialized = Serializer::deserialize(serialized);
//   std::cout << "Deserialized NULL: " << deserialized << std::endl;
//   std::cout << "Match: " << (nullPtr == deserialized ? "YES" : "NO")
//             << std::endl;
//   std::cout << std::endl;
// }

int main() {
  testBasicSerialization();
  // testMultipleObjects();
  // testNullPointer();

  std::cout << "=== All tests completed ===" << std::endl;
  return 0;
}
