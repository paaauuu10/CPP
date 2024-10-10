#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::setFirstName(std::string str)
{
	this->FirstName = str;
}
void Contact::setLastName(std::string str)
{
	this->LastName = str;
}
void Contact::setNickname(std::string str)
{
	this->Nickname = str;
}
void Contact::setPhoneNumber(std::string str)
{
	this->PhoneNumber = str;
}
void Contact::setDarkestSecret(std::string str)
{
	this->DarkestSecret = str;
}

std::string Contact::getFirstName(void) const
{
	return (this->FirstName);
}
std::string Contact::getLastName(void) const
{
	return (this->LastName);
}
std::string Contact::getNickname(void) const
{
	return (this->Nickname);
}
std::string Contact::getPhoneNumber(void) const
{
	return (this->PhoneNumber);
}
std::string Contact::getDarkestSecret(void) const
{
	return (this->DarkestSecret);
}