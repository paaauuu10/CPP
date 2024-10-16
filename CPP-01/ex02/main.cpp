#include <iostream>

int main() {
    
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory addres of the string is: " << &str << std::endl; 
    std::cout << "The memory addres of the stringPTR: " << stringPTR << std::endl; 
    std::cout << "The memory addres of the stringREF: " << &stringREF << std::endl; 

    std::cout << "The value of the string is: " << str << std::endl; 
    std::cout << "The value of the stringPTR is: " << stringREF << std::endl; 
    std::cout << "The value of the stringREF is: " << stringREF << std::endl; 

    return (0);
}