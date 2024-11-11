/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 17:03:56 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("Uri", 51);
	Form form("Contracte", 50, 10);
	
	std::cout << form << std::endl;
	std::cout << "Probamos de firmar el Form:" << std::endl;
	try 
	{
		form.beSigned(b1);
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Incrementamos " << b1.getName() << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	std::cout << "Lo intentamos de nuevo:" << std::endl;
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