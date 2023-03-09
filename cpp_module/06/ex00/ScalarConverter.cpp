//
// Created by Hanbin Kim on 3/3/23.
//

#include <iostream>
#include <climits>
#include <cfloat>
#include <cerrno>
#include "ScalarConverter.hpp"


bool ScalarConverter::canConvertInt = true;

ScalarConverter::DataType (*const ScalarConverter::typeCheck[4])(const std::string &str) = {
    &isChar,
    &isInt,
    &isFloat,
    &isDouble
};

void ScalarConverter::convert(const std::string &str) {
  switch (getType(str)) {
    case CHAR:convertChar(static_cast<char>(str[0]));
      break;
    case INT:convertInt(static_cast<int>(strtol(str.c_str(), NULL, 10)));
      break;
    case FLOAT:convertFloat(static_cast<float>(strtod(str.c_str(), NULL)));
      break;
    case DOUBLE:convertDouble(strtod(str.c_str(), NULL));
      break;
    case NONE:std::cout << "impossible conversion\n";
      break;
  }
}

ScalarConverter::DataType ScalarConverter::getType(const std::string &str) {
  for (int i = 0; i < 4; ++i) {
    DataType type = typeCheck[i](str);
    if (type != NONE)
      return type;
  }
  return NONE;
}

ScalarConverter::DataType ScalarConverter::isChar(const std::string &str) {
  if (str.length() == 1 && isascii(str[0]))
    return CHAR;
  return NONE;
}

ScalarConverter::DataType ScalarConverter::isInt(const std::string &str) {
  char *endPoint;
  long long value = strtol(str.c_str(), &endPoint, 10);

  if (errno == ERANGE) {
    errno = 0;
    return NONE;
  }
  if (value > INT_MAX || value < INT_MIN)
    return NONE;
  if (*endPoint != '\0')
    return NONE;
  if (str.find('.') != std::string::npos)
    return NONE;
  if (str.find('f') != std::string::npos)
    return NONE;
  return INT;
}

ScalarConverter::DataType ScalarConverter::isFloat(const std::string &str) {
  char *endPoint;
  double value = strtod(str.c_str(), &endPoint);

  if(str == "inff" || str == "-inff" || str == "+inff" || str == "nanf") {
    canConvertInt = false;
    return FLOAT;
  }
  if (static_cast<long long>(value) != static_cast<int>(value)) {
    std::cout << value << " " << static_cast<int>(value) << std::endl;
    canConvertInt = false;
  }
  if (errno == ERANGE) {
    errno = 0;
    return NONE;
  }
  if (*endPoint != 'f')
    return NONE;
  if (value > FLT_MAX || value < -FLT_MAX)
    return NONE;
  return FLOAT;
}

ScalarConverter::DataType ScalarConverter::isDouble(const std::string &str) {
  char *endPoint;
  double value = strtod(str.c_str(), &endPoint);

  if(str == "inf" || str == "-inf" || str == "+inf" || str == "nan") {
    canConvertInt = false;
    return DOUBLE;
  }
  if (static_cast<long long>(value) != static_cast<int>(value)) {
    std::cout << value << " " << static_cast<int>(value) << std::endl;
    canConvertInt = false;
  }
  if (str.find('.') == std::string::npos)
    return NONE;
  if (errno == ERANGE) {
    errno = 0;
    return NONE;
  }
  if (*endPoint != '\0')
    return NONE;
  return DOUBLE;
}

void ScalarConverter::convertChar(char value) {
  if (isprint(value))
    std::cout << "char: " << value << '\n';
  else if (!isprint(value))
    std::cout << "char: " << "Non displayable" << '\n';
  else
    std::cout << "char: " << "impossible" << '\n';

  std::cout << "int: " << static_cast<int>(value) << '\n';

  float fValue = static_cast<float>(value);
  if (fmod(fValue, 1.0) == 0.0)
    std::cout << "float: " << fValue << ".0f\n";
  else
    std::cout << "float: " << fValue << "f\n";

  double dValue = static_cast<double>(value);
  if (fmod(dValue, 1.0) == 0.0)
    std::cout << "double: " << dValue << ".0\n";
  else
    std::cout << "double: " << dValue << "\n";
}

void ScalarConverter::convertInt(int value) {
  if (isascii(value)) {
    if (!isprint(value))
      std::cout << "char: " << "Non displayable" << '\n';
    else
      std::cout << "char: " << static_cast<char>(value) << '\n';
  } else
    std::cout << "char: " << "impossible" << '\n';

  std::cout << "int: " << value << '\n';

  float fValue = static_cast<float>(value);
  if (fmod(fValue, 1.0) == 0.0)
    std::cout << "float: " << fValue << ".0f\n";
  else
    std::cout << "float: " << fValue << "f\n";

  double dValue = static_cast<double>(value);
  if (fmod(dValue, 1.0) == 0.0)
    std::cout << "double: " << dValue << ".0\n";
  else
    std::cout << "double: " << dValue << "\n";
}

void ScalarConverter::convertFloat(float value) {
  if (isascii(static_cast<int>(value))) {
    if (!isprint(static_cast<int>(value)))
      std::cout << "char: " << "Non displayable" << '\n';
    else
      std::cout << "char: " << static_cast<char>(value) << '\n';
  } else
    std::cout << "char: " << "impossible" << '\n';

  if (canConvertInt)
    std::cout << "int: " << static_cast<int>(value) << '\n';
  else
    std::cout << "int: " << "impossible" << '\n';

  if (fmod(value, 1.0) == 0.0)
    std::cout << "float: " << value << ".0f\n";
  else
    std::cout << "float: " << value << "f\n";

  double dValue = static_cast<double>(value);
  if (fmod(dValue, 1.0) == 0.0)
    std::cout << "double: " << dValue << ".0\n";
  else
    std::cout << "double: " << dValue << "\n";
}

void ScalarConverter::convertDouble(double value) {
  if (isascii(static_cast<int>(value))) {
    if (!isprint(static_cast<int>(value)))
      std::cout << "char: " << "Non displayable" << '\n';
    else
      std::cout << "char: " << static_cast<char>(value) << '\n';
  } else
    std::cout << "char: " << "impossible" << '\n';

  if (canConvertInt)
    std::cout << "int: " << static_cast<int>(value) << '\n';
  else
    std::cout << "int: " << "impossible" << '\n';

  float fValue = static_cast<float>(value);
  if (fmod(fValue, 1.0) == 0.0)
    std::cout << "float: " << fValue << ".0f\n";
  else
    std::cout << "float: " << fValue << "f\n";

  if (fmod(value, 1.0) == 0.0)
    std::cout << "double: " << value << ".0\n";
  else
    std::cout << "double: " << value << "\n";
}
