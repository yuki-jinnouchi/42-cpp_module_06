#include "ScalarConverter.hpp"

#include <cctype>

// Private constructor - cannot be instantiated
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

// Type detection methods
bool ScalarConverter::isChar(const std::string& literal) {
  if (literal.empty()) return false;
  if (literal.length() != 3) return false;
  if (literal[0] != '\'' || literal[2] != '\'') return false;
  return true;
}

bool ScalarConverter::isInt(const std::string& literal) {
  if (literal.empty()) return false;
  return isValidNumber(literal, 0, 1);
}

bool ScalarConverter::isFloat(const std::string& literal) {
  if (literal.length() < 2 || literal.back() != 'f') return false;

  if (literal == "-inff" || literal == "+inff" || literal == "inff" ||
      literal == "nan")
    return true;

  std::string withoutF = literal.substr(0, literal.length() - 1);
  return isValidNumber(withoutF, 1, 1);
}

bool ScalarConverter::isDouble(const std::string& literal) {
  if (literal == "-inf" || literal == "+inf" || literal == "inf" ||
      literal == "nan")
    return true;

  return isValidNumber(literal, 1, 1);
}

// Helper methods
bool ScalarConverter::isValidNumber(const std::string& str,
                                    int requiredDotCount, int minDigitCount) {
  if (str.empty()) return false;

  size_t start = 0;
  if (str[0] == '+' || str[0] == '-') start++;
  if (start == str.length()) return false;

  int dotCount = 0;
  int digitCount = 0;

  for (size_t i = start; i < str.length(); i++) {
    if (str[i] == '.') {
      dotCount++;
      if (dotCount > 1) return false;
    } else if (std::isdigit(str[i])) {
      digitCount++;
    } else {
      return false;
    }
  }

  return dotCount == requiredDotCount && digitCount >= minDigitCount;
}

// Type-specific conversion methods
void ScalarConverter::convertFromChar(const std::string& literal) {
  char c = literal[1];

  // Print char (own type)
  if (static_cast<int>(c) >= 0 && static_cast<int>(c) <= 127 &&
      std::isprint(static_cast<int>(c))) {
    std::cout << "char: '" << c << "'" << std::endl;
  } else if (static_cast<int>(c) >= 0 && static_cast<int>(c) <= 127) {
    std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }

  // Convert to other types
  int intValue = static_cast<int>(c);
  float floatValue = static_cast<float>(c);
  double doubleValue = static_cast<double>(c);

  std::cout << "int: " << intValue << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal) {
  long longValue = std::atol(literal.c_str());

  // Handle integer overflow
  if (longValue > std::numeric_limits<int>::max() ||
      longValue < std::numeric_limits<int>::min()) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(longValue) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(longValue) << std::endl;
    return;
  }

  int intValue = static_cast<int>(longValue);

  // Convert to char
  if (intValue >= 0 && intValue <= 127 && std::isprint(intValue)) {
    std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
  } else if (intValue >= 0 && intValue <= 127) {
    std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }

  // Print int (own type)
  std::cout << "int: " << intValue << std::endl;

  // Convert to other types
  float floatValue = static_cast<float>(intValue);
  double doubleValue = static_cast<double>(intValue);

  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& literal) {
  float floatValue = static_cast<float>(std::atof(literal.c_str()));

  // Convert to char
  if (floatValue != static_cast<int>(floatValue)) {
    // Has decimal part - cannot convert to char
    std::cout << "char: impossible" << std::endl;
  } else {
    int intValue = static_cast<int>(floatValue);
    if (intValue >= 0 && intValue <= 127 && std::isprint(intValue)) {
      std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    } else if (intValue >= 0 && intValue <= 127) {
      std::cout << "char: Non displayable" << std::endl;
    } else {
      std::cout << "char: impossible" << std::endl;
    }
  }

  // Convert to int
  if (!isInIntRange(static_cast<double>(floatValue))) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
  }

  // Print float (own type)
  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;

  // Convert to double
  double doubleValue = static_cast<double>(floatValue);
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal) {
  double doubleValue = std::atof(literal.c_str());

  // Convert to char
  if (std::isnan(doubleValue) || std::isinf(doubleValue)) {
    std::cout << "char: impossible" << std::endl;
  } else if (doubleValue != static_cast<int>(doubleValue)) {
    // Has decimal part - cannot convert to char
    std::cout << "char: impossible" << std::endl;
  } else {
    int intValue = static_cast<int>(doubleValue);
    if (intValue >= 0 && intValue <= 127 && std::isprint(intValue)) {
      std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    } else if (intValue >= 0 && intValue <= 127) {
      std::cout << "char: Non displayable" << std::endl;
    } else {
      std::cout << "char: impossible" << std::endl;
    }
  }

  // Convert to int
  if (std::isnan(doubleValue) || std::isinf(doubleValue) ||
      !isInIntRange(doubleValue)) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
  }

  // Convert to float
  float floatValue = static_cast<float>(doubleValue);
  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;

  // Print double (own type)
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

void ScalarConverter::convertFromPseudo(const std::string& literal) {
  // All pseudo literals make char and int impossible
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  // Handle float pseudo literals
  if (literal.find("nan") != std::string::npos) {
    std::cout << "float: nanf" << std::endl;
  } else if (literal.find("-inf") != std::string::npos) {
    std::cout << "float: -inff" << std::endl;
  } else {
    std::cout << "float: +inff" << std::endl;
  }

  // Handle double pseudo literals
  if (literal.find("nan") != std::string::npos) {
    std::cout << "double: nan" << std::endl;
  } else if (literal.find("-inf") != std::string::npos) {
    std::cout << "double: -inf" << std::endl;
  } else {
    std::cout << "double: +inf" << std::endl;
  }
}

// Utility output method
void ScalarConverter::printAllImpossible() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

// Utility methods
bool ScalarConverter::isInIntRange(double value) {
  return (value >= std::numeric_limits<int>::min() &&
          value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::hasDecimalPart(double value) {
  return (value != static_cast<int>(value));
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
  return (literal == "-inf" || literal == "+inf" || literal == "inf" ||
          literal == "nan" || literal == "-inff" || literal == "+inff" ||
          literal == "inff" || literal == "nanf");
}

void ScalarConverter::convert(const std::string& literal) {
  if (isChar(literal)) {
    convertFromChar(literal);
  } else if (isPseudoLiteral(literal)) {
    convertFromPseudo(literal);
  } else if (isInt(literal)) {
    convertFromInt(literal);
  } else if (isFloat(literal)) {
    convertFromFloat(literal);
  } else if (isDouble(literal)) {
    convertFromDouble(literal);
  } else {
    // Invalid input
    printAllImpossible();
  }
}
