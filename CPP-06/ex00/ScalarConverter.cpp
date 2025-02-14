#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>
#include <climits>
#include <iomanip>
#include <cfloat>

void ScalarConverter::impossible(){
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printChar(char c){
    std::cout << "char: " << c << std::endl;  
    std::cout << "int: " << static_cast<int>(c) << std::endl;  
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;  
}

void ScalarConverter::printInfinite(std::string str){
    if (str == "-inff" || str == "+inff" || str == "nanf"){
        std::cout << "char: Non displayable" << std::endl;  
        std::cout << "int: Non displayable" << std::endl;  
        std::cout << "float: " << str << std::endl;
        str.resize(str.size() - 1);  
        std::cout << "double: " << str << std::endl;  
    }
    else{
        std::cout << "char: Non displayable" << std::endl;  
        std::cout << "int: Non displayable" << std::endl;  
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;  
    }
}

void ScalarConverter::printInt(std::string str){
    double d = atof(str.c_str());
    if (d < INT_MIN || d > INT_MAX) {
        impossible();
        return;
    }
    int temp = atoi(str.c_str());
    char c = static_cast<char>(temp);
    if (temp >= 0 && temp <= 127 && std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << temp << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(temp) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(temp) << std::endl;    
}

void ScalarConverter::printDouble(double d){
    char c = static_cast<char>(d);
    if (d >= 0 && d <= 127 && std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else	
        std::cout << "char: Non displayable" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl;
    if (d >= -FLT_MAX && d <= FLT_MAX)
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;  
}

void ScalarConverter::printFloat(std::string str){
    double d = atof(str.c_str());
    if(d < -FLT_MAX || d > FLT_MAX){
        impossible();
        return;
    }
    float f = static_cast<float>(atof(str.c_str()));
    char c = static_cast<char>(f);
    if (f >= 0 && f <= 127 && std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else	
        std::cout << "char: Non displayable" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

bool ScalarConverter::isValidInt(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (i == 0 && str[i] == '-') {
            if (str[i + 1])
                continue;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isValidDouble(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (i == 0 && str[i] == '-') {
            continue;
        } else if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isValidFloat(const std::string& str) {
    if (str[str.size() - 1] != 'f') {
		return false;
	}
	for (size_t i = 0; i < str.length(); i++) {
        if (i == 0 && str[i] == '-') {
            continue;
        } else if (!isdigit(str[i]) && str[i] != '.' && (i < str.length() - 1 && str[i] == 'f')) {
            return false;
        }
    }
    return true;
}

void ScalarConverter::convert(std::string str){
    if (str.empty()){
        std::cout << "Error! You are passing an empty string!" << std::endl;
        return;
    }
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf"
        || str == "+inf" || str == "nan"){
            printInfinite(str);
            return;
    }
    else if (!isdigit(str[0]) && str.size() == 1){
        if (std::isprint(str[0])){
            printChar(str[0]);
            return;
        }
        else{
            std::cout << "This is a non displayable character." << std::endl;
            return;
        }
    }
    else if (str.find(".") == std::string::npos){
        if (isValidInt(str)) {
            printInt(str);
        } else {
            std::cout << "That's an incorrect string!" << std::endl;
        }
    }
    else if (str.find(".") != std::string::npos && str.find("f") == std::string::npos){
        if (isValidDouble(str)) {
            printDouble(atof(str.c_str()));
        } else {
            std::cout << "That's an incorrect string!" << std::endl;
        }
    }
    else if (str.find(".") != std::string::npos && str.find("f") != std::string::npos){
        if (isValidFloat(str)) {
            printFloat(str);
        } else {
            std::cout << "That's an incorrect string!" << std::endl;
        }
    }
    else{
        std::cout << "That's an incorrect string!" << std::endl;
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }