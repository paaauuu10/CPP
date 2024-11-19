/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/19 12:37:39 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int main(void)
{
	ShrubberyCreationForm	shrubberry("shru");
	RobotomyRequestForm		robotomy("robo");
	PresidentialPardonForm	presidential("pres");

	Bureaucrat				bureucrat("Pau", 2);
	Bureaucrat				bureaucrat2("Alba", 71);
	Bureaucrat				bureaucrat3("Botargues", 150);

	std::cout << std::endl;
	std::cout << "Torn: " << bureucrat.getName() << std::endl; 
	try
	{
		bureucrat.signForm(shrubberry);
		bureucrat.executeForm(shrubberry);
		std::cout << std::endl;
		bureucrat.signForm(robotomy);
		bureucrat.executeForm(robotomy);
		std::cout << std::endl;
		bureucrat.signForm(presidential);
		bureucrat.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Torn: " << bureaucrat2.getName() << std::endl;
	try
	{
		bureaucrat2.signForm(shrubberry);
		bureaucrat2.executeForm(shrubberry);
		std::cout << std::endl;
		bureaucrat2.signForm(robotomy);
		bureaucrat2.executeForm(robotomy);
		std::cout << std::endl;
		bureaucrat2.signForm(presidential);
		bureaucrat2.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Torn: " << bureaucrat3.getName() << std::endl;
	try
	{
		bureaucrat3.signForm(shrubberry);
		bureaucrat3.executeForm(shrubberry);
		std::cout << std::endl;
		bureaucrat3.signForm(robotomy);
		bureaucrat3.executeForm(robotomy);
		std::cout << std::endl;
		bureaucrat3.signForm(presidential);
		bureaucrat3.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}