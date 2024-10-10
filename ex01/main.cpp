#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook		phone;
    std::string		input;
    bool    		loop = true;

    while (loop)
    {
        std::cout << "\033[1;32m";
        std::cout << "SELECT --> ADD, SEARCH or EXIT" << std::endl;
        std::cout << "\033[0m";
        std::getline(std::cin, input);
        if (std::cin.fail())
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        if (input == "ADD")
        {
        	if (phone.add() == 1)
            return (1);
        }
        else if (input == "SEARCH")
        {
            if (phone.search() == 1)
                return (1);
        }
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
