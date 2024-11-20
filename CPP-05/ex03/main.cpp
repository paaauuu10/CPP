/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/20 11:39:28 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main(void)
{
	Intern	intern0;
	AForm	*form;
	Bureaucrat				bureucrat("Uri", 45);
	

	std::cout << std::endl;
	try
	{
		form = intern0.makeForm("shrubbery creation", "shru");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
		form = intern0.makeForm("robotomy request", "robo");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
		form = intern0.makeForm("presidential pardon", "presi");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		form = intern0.makeForm("pau form", "pf");
		if (form != NULL)
		{
			bureucrat.signForm(*form);
			bureucrat.executeForm(*form);
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}