/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:29 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/20 10:44:57 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("Pau", 60);
	Bureaucrat b2("Alba", 150);
	std::cout << std::endl;
	try
	{
		Bureaucrat b3("Error", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << b1 << std::endl;
	std::cout << "Incrementem: " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	std::cout << "Decrementem: " << b1.getName() << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl << std::endl;
	
	std::cout << b2 << std::endl;
	std::cout << "Decrementem: " << b2.getName() << std::endl;
	try
	{
		b2.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b2<< std::endl << std::endl;
	std::cout << std::endl;
	Bureaucrat b4("B4", 1);
	try
	{
		std::cout << "Incrementem: " << b4.getName() << std::endl;
		b4.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}