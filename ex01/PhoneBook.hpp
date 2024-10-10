#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <limits>
#include	"Contact.hpp"
class PhoneBook
{
	private:
		Contact	person[8];
		int		size;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		add(void);
		int		search(void);
		void	printContactInfo(int index);
		void 	display(std::string str);
		void	printRequest(std::string str);
};

#endif
