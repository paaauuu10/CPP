/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:29 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 12:55:53 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("Uri", 60);
	Bureaucrat b2(b1);
	Bureaucrat b3("Laura", 150);
	try
	{
		Bureaucrat b4("Mal", 151); //Habrá excepcion
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << "Incrementamos " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	
	std::cout << b2 << std::endl;
	std::cout << "Incrementamos " << b2.getName() << std::endl;
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
	std::cout << "Decrementamos " << b3.getName() << std::endl;
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