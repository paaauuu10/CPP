/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:19 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 09:47:52 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
   std::cout << "Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
   std::cout << "Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Operator '=' called" << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

~Bureaucrat()
{
    std::cout << this->_name << " destructor called" << std::endl; 
}