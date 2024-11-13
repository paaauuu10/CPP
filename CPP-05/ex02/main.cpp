/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:32 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/13 16:48:24 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int main(void)
{
	ShrubberyCreationForm sh("homeee");
	std::cout << std::endl;
	ShrubberyCreationForm sh1(sh);
	std::cout << std::endl;
	std::cout << sh1.getTarget();
	sh1.executeAction();
	std::cout << std::endl;
	std::cout << std::endl;



}