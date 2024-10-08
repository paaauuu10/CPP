#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook		phone;
    std::string		input;
    bool    		loop = true;

    while (loop)
    {
     
        std::cout << "\033[1;32m";  // 1 es para negrita, 32 es el código de color verde
        std::cout << "SELECT --> ADD, SEARCH or EXIT" << std::endl;
        std::cout << "\033[0m";
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        if (input == "ADD")
        	phone.add();
		else if (input == "SEARCH") 
            std::cout << "What do u want to search?" << std::endl;
        else if (input == "EXIT")
            loop = false;
        else
        { 
            std::cout << "\033[1;31m";
            std::cout << "This is not a valid argument" << std::endl;
            std::cout << "\033[0m";
        }
    }
    return (0);
}
