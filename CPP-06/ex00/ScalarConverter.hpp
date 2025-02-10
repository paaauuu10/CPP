#include <string>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

public:
    static void convert(std::string str);
    static void	printInfinite(std::string str);
    static void	printInt(std::string str);
    static void printChar(char c);
    

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

};

#endif // SCALARCONVERTER_HPP