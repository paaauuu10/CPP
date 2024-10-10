#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "PhoneBook.hpp"

class	Contact
{
	private:
		std::string FirstName;
		std::string	LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		//Contact();
		//~Contact();
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;

		void	displayContact(void) const;
};

#endif
