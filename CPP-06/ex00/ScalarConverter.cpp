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
		std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(c) << "f" << std::endl; //revisar si cal fer --> "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f""
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;  
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


void ScalarConverter::printInt(std::string str){
	// Intentamos convertir la cadena a un número double
	//Lo hacemos con double porque si hacemos el atoi de un > que MAX_INT ATOI DA -1
    double d = atof(str.c_str());

    // Verificamos si el número está dentro del rango de un int
    if (d < INT_MIN || d > INT_MAX) {
		impossible();
		return ;
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

	/*if (d < DBL_MIN || d > DBL_MAX){
		impossible();
		return;
	}*/
	
	if (d >= 0 && d <= 127 && std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else	
		std::cout << "char: Non displayable" << std::endl;
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else 
		std::cout << "int: impossible" << std::endl;
	if (d >= FLT_MIN && d <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;  
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
	else if (!isdigit(str[0]) && str.size() == 1){
		if (std::isprint(str[0])){
			printChar(str[0]);
			return ;
		}
		else{
			std::cout << "This is a non displayable character." << std::endl;
			return ;
		}
	}
	else if (str.find(".") == std::string::npos){
		for (size_t i = 0; i < str.length(); i++){
			if (i == 0 && str[i] == '-'){
				if (str[i + 1])
					i++;
			}
			else if (!isdigit(str[i])){
				std::cout << "That's an incorrect string!" << std::endl;
				return ;
			}
		}
		printInt(str);
	}
	else if (str.find(".") != std::string::npos && str.find("f") == std::string::npos){
		for (size_t i = 0; i < str.length(); i++){
			if (i == 0 && str[i] == '-'){
				continue ;
			}
			else if (!isdigit(str[i]) && str[i] != '.'){
				std::cout << "That's an incorrect string!" << std::endl;
				return ;
			}
		}
		printDouble(atof(str.c_str()));	
	}
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }