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
void	displayTableHeader(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
void PhoneBook::search(void)
{
	int i = 0;
	if (this->size < 1)
	{
		std::cout << "\033[1;31m";
		std::cout << "Empty guide" << std::endl;
		std::cout << "\033[0m";
		return ;
	}
	displayTableHeader();
	
	while ()
}
void PhoneBook::add(void)
{
	std::string 	input;

	std::cout << "First Name: ";
	std::cin >> input;
	person[this->size % 8].setFirstName(input);
	std::cout << "Last Name: ";
	std::cin >> input;
	person[this->size % 8].setLastName(input);
	std::cout << "Nickname: ";
	std::cin >> input;
	person[this->size % 8].setNickname(input);
	std::cout << "PhoneNumber: ";
	std::cin >> input;
	person[this->size % 8].setPhoneNumber(input);
	std::cout << "DarkestSecret: ";
	std::cin >> input;
	person[this->size % 8].setDarkestSecret(input);
	this->size++;
}
