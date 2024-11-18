/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 17:22:41 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main(void)
{
	Intern	novato;
	AForm	*form;
	Bureaucrat				bureucrat("Uri", 45);
	

	std::cout << std::endl;
	std::cout << "Turn: " << bureucrat.getName() << std::endl; 
	try
	{
		form = novato.makeForm("shrubbery creation", "home");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
		form = novato.makeForm("robotomy request", "Bender");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
		form = novato.makeForm("presidential pardon", "Jefe");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}