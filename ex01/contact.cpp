#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::foundFirstName(std::string str)
{
	this->FirstName = str;
}
void Contact::foundLastName(std::string str)
{
	this->LastName = str;
}
