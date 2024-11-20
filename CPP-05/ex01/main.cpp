/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/20 10:57:51 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("Pau", 10);
	Form form("Contracte", 9, 10);	
	std::cout << form << std::endl;
	std::cout << "Firmem Form: " << std::endl;
	std::cout << b1 << std::endl;
	try 
	{
		form.beSigned(b1);
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Incrementem: " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	std::cout << "Firmem Form:" << std::endl;
	try 
	{
		form.beSigned(b1);
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}