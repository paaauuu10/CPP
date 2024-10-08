#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "\033[1;32m";
	this->size = 0;
	std::cout << "Welcome to PhoneBook" << std::endl;
	std::cout << "\033[0m";
}

PhoneBook::~PhoneBook(void)
{
}
void PhoneBook::add(void)
{
	std::string 	input;
	Contact			cont;
	bool			check = false;

	while (!check)
	{
		std::cout << "First Name: ";
		std::cin >> input;
		cont.foundFirstName(input);
		std::cout << "Last Name: ";
		std::cin >> input;
		cont.foundLastName(input);
		check = true;
	}
}
