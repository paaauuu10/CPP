#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>

void ScalarConverter::printChar(char c){
		std::cout << "char: " << c << std::endl;  
		std::cout << "int: " << static_cast<int>(c) << std::endl;  
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl; //revisar si cal fer --> "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f""
		std::cout << "double: " << static_cast<double>(c) << std::endl;  

}	

//HEM DE REPASAR PERQUE AIXO ES AIXI
void	ScalarConverter::printInfinite(std::string str){
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



void ScalarConverter::convert(std::string str){
	if (str.empty()){
		std::cout << "Error! You are passing an empty string!" << std::endl;
	}
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf"
		|| str == "+inf" || str == "nan"){
			printInfinite(str);
			return ;
		}
	else if (!isdigit(str[0])){
		if (std::isprint(str[0])){
			printChar(str[0]);
			return ;
		}
		else{
			std::cout << "This is a non displayable character." << std::endl;
			return ;
		}
	}
	else if ()

	
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }