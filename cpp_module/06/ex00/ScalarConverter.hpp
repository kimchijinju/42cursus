//
// Created by Hanbin Kim on 3/3/23.
//

#ifndef INC_06_EX00_SCALARCONVERTER_HPP_
#define INC_06_EX00_SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string &str);

 private:
  enum DataType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NONE
  };

  static void convertChar(char value);
  static void convertInt(int value);
  static void convertFloat(float value);
  static void convertDouble(double value);

  static DataType isChar(const std::string &str);
  static DataType isInt(const std::string &str);
  static DataType isFloat(const std::string &str);
  static DataType isDouble(const std::string &str);

  static DataType getType(const std::string &str);

  static DataType (*const typeCheck[4])(const std::string &str);

  static bool canConvertInt;

 private: // not use

  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &scalarConverter);
  ScalarConverter &operator= (const ScalarConverter &scalarConverter);

};

#endif //INC_06_EX00_SCALARCONVERTER_HPP_
