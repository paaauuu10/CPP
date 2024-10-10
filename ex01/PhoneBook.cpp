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

void	IndexHeader(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
void PhoneBook::printContactInfo(int index)
{
	std::cout << "FirstName: " << person[index].getFirstName() << std::endl; 
	std::cout << "LasName: " << person[index].getLastName() << std::endl; 
	std::cout << "Nickname: " << person[index].getNickname() << std::endl; 
	std::cout << "PhoneNumber: " << person[index].getPhoneNumber() << std::endl; 
	std::cout << "DarkestSecret: " << person[index].getDarkestSecret() << std::endl; 

}
void	printSpaces(int len)
{
	while (len < 10)
	{
		std::cout << " ";
		len++;
	}
}
void PhoneBook::display(std::string str)
{
	int len;
	len = str.length();
	if (len > 11)
	{
		str.resize(9);
		str += ".";
		len = str.length();
	}
	printSpaces(len);
	std::cout << str << "|";
}
int	setIndex(std::string str)
{
	if (str == "0")
		return (0);
	else if (str == "1")
		return (1);
	else if (str == "2")
		return (2);
	else if (str == "3")
		return (3);
	else if (str == "4")
		return (4);
	else if (str == "5")
		return (5);
	else if (str == "6")
		return (6);
	else if (str == "7")
		return (7);
	else
		return (10);


}
int PhoneBook::search(void)
{
	if (this->size < 1)
	{
		std::cout << "\033[1;31m";
		std::cout << "Empty guide" << std::endl;
		std::cout << "\033[0m";
		return (2);
	}
	IndexHeader();
	int i = 0;
	int	totalLoop = this->size;
	if (this->size > 8)
		totalLoop = 8;
	while (i < totalLoop)
	{
		std::cout << "|";
		std::cout << "         " << i << "|";
		std::string str;
		display(str = person[i].getFirstName());
		display(str = person[i].getLastName());
		display(str = person[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::string input;
	int index;
	std::cout << "|-------------------------------------------|" << std::endl;
	i = 0;
	while (i == 0)
	{
		printRequest("Please insert the Index you want to show: ");
		std::getline(std::cin, input);
		if (std::cin.fail())
    	{
        	    std::cout << "Error" << std::endl;
            	return (1);
   		}
		index = setIndex(input);
		if (index >= 0 && index < 8 && index < this->size){
			printContactInfo(index);
			i = 1;}
		else 
		{
			std::cout << "\033[1;31m";
			std::cout << "This is not a valid index" << std::endl;
			std::cout << "\033[0m";
		}}
	return (0);
}

void displayError(std::string str)
{
	std::cout << "\033[1;31m";
    std::cout << str << std::endl;
	std::cout << "\033[0m";
}
void	PhoneBook::printRequest(std::string str)
{
	std::cout << "\033[1;32m";
    std::cout << str;
	std::cout << "\033[0m";
}

int PhoneBook::add(void)
{
	std::string 	input;
	int	i = 0;
	while (i == 0){
		printRequest("First Name: ");
		std::getline(std::cin, input);
		if (std::cin.fail()){
			std::cout << "Error" << std::endl;
    		return (1);}
		if (input.empty())
			displayError("You can't leave this field empty!");
		else{
			person[this->size % 8].setFirstName(input);
			i = 1;}}
	i = 0;
	while (i == 0){
		printRequest("Last Name: ");
		std::getline(std::cin, input);
		if (std::cin.fail()){
        	std::cout << "Error" << std::endl;
    		return (1);}
		if (input.empty())
			displayError("You can't leave this field empty!");
		else {
			person[this->size % 8].setLastName(input);
			i = 1;}}
	i = 0;
	while (i == 0){
		printRequest("Nickname: ");
		std::getline(std::cin, input);
		if (std::cin.fail()){
        	std::cout << "Error" << std::endl;
    		return (1);}
		if (input.empty())
			displayError("You can't leave this field empty!");
		else {
			person[this->size % 8].setNickname(input);
			i = 1;}}
	i = 0;
	while (i == 0){
		printRequest("PhoneNumber: ");
		std::getline(std::cin, input);
		if (std::cin.fail()){
        	std::cout << "Error" << std::endl;
    		return (1);}
		if (input.empty())
			displayError("You can't leave this field empty!");
		else {
			person[this->size % 8].setPhoneNumber(input);
			i = 1;}}
	i = 0;
	while (i == 0){
		printRequest("DarkestSecret: ");
		std::getline(std::cin, input);
		if (std::cin.fail()){
        	std::cout << "Error" << std::endl;
    		return (1);}
		if (input.empty())
			displayError("You can't leave this field empty!");
		else {
			person[this->size % 8].setDarkestSecret(input);
			i = 1;}}
	this->size++;
	return (0);
}
