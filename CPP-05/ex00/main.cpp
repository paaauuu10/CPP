/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:29 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/19 12:34:24 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("Pau", 60);
	Bureaucrat b2(b1);
	Bureaucrat b3("Alba", 150);
	try
	{
		Bureaucrat b4("Error", 151); //Habrá excepcion
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << "Incrementem: " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	
	std::cout << b2 << std::endl;
	std::cout << "Incrementem: " << b2.getName() << std::endl;
	try
	{
		b2.incrementGrade();//Habrá excepcion
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b2<< std::endl << std::endl;

	std::cout << b3 << std::endl;
	std::cout << "Decrementem: " << b3.getName() << std::endl;
    try
	{
		b3.decrementGrade();//Habrá excepcion
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b3<< std::endl << std::endl;
}