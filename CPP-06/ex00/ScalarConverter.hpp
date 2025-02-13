#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

public:
    static void convert(std::string str);

private:
    static void printInfinite(std::string str);
    static void printInt(std::string str);
    static void printChar(char c);
    static void printDouble(double d);
    static void printFloat(std::string str);
    static void impossible();

    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

    static bool isValidInt(const std::string& str);
    static bool isValidDouble(const std::string& str);
    static bool isValidFloat(const std::string& str);
};

#endif // SCALARCONVERTER_HPP