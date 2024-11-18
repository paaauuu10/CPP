/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 15:29:17 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int main(void)
{
	ShrubberyCreationForm	shrubberry("Home");
	RobotomyRequestForm		robotomy("Cerebro");
	PresidentialPardonForm	presidential("President");

	Bureaucrat				bureucrat("Uri", 2);
	Bureaucrat				bur2("A", 71);
	Bureaucrat				bur3("B", 150);

	std::cout << std::endl;
	std::cout << "Turn: " << bureucrat.getName() << std::endl; 
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
	std::cout << "Turn: " << bur2.getName() << std::endl;
	try
	{
		bur2.signForm(shrubberry);
		bur2.executeForm(shrubberry);
		std::cout << std::endl;
		bur2.signForm(robotomy);
		bur2.executeForm(robotomy);
		std::cout << std::endl;
		bur2.signForm(presidential);
		bur2.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Turn: " << bur3.getName() << std::endl;
	try
	{
		bur3.signForm(shrubberry);
		bur3.executeForm(shrubberry);
		std::cout << std::endl;
		bur3.signForm(robotomy);
		bur3.executeForm(robotomy);
		std::cout << std::endl;
		bur3.signForm(presidential);
		bur3.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}