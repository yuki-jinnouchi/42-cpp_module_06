#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
 private:
  // Private constructor to prevent instantiation
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();

  // Type detection methods
  static bool isChar(const std::string& literal);
  static bool isInt(const std::string& literal);
  static bool isFloat(const std::string& literal);
  static bool isDouble(const std::string& literal);
  static bool isPseudoLiteral(const std::string& literal);

  // Type-specific conversion methods
  static void convertFromChar(const std::string& literal);
  static void convertFromInt(const std::string& literal);
  static void convertFromFloat(const std::string& literal);
  static void convertFromDouble(const std::string& literal);
  static void convertFromPseudo(const std::string& literal);

  // Utility output method
  static void printAllImpossible();

  // Utility methods
  static bool isValidNumber(const std::string& str, int requiredDotCount = 1,
                            int minDigitCount = 2);
  static bool isInIntRange(double value);
  static bool hasDecimalPart(double value);

 public:
  static void convert(const std::string& literal);
};

#endif
