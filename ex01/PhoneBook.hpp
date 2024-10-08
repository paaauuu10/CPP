#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include	"Contact.hpp"
class PhoneBook
{
	private:
		Contact	person[8];
		int		size;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif
