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
		void	foundFirstName(std::string str);
		void	foundLastName(std::string str);
		/*		void	setNikname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string getNikname(void) const;
		std::string getPhone(void) const;
		std::string	getDarkestSecret(void) const;

		void	displayContact(void) const;*/
};

#endif
