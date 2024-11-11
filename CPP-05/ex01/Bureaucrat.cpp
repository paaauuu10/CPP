/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:19 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 17:06:44 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
   std::cout << "Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
   std::cout << "Default constructor called" << std::endl;
   this->setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
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

Bureaucrat::~Bureaucrat()
{
    std::cout << this->_name << " destructor called" << std::endl; 
}

std::string Bureaucrat::getName()const
{
    return (this->_name);
}
int Bureaucrat::getGrade()const
{
    return (this->_grade);   
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        this->_grade = grade; 
}
void Bureaucrat::incrementGrade()
{
    this->setGrade(this->_grade - 1);        
}

void Bureaucrat::decrementGrade()
{
    this->setGrade(this->_grade + 1);        
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("That's impossible! Grade can´t be a lower integer than 1");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("That's impossible! Grade can't be a bigger integer than 150");
}

void Bureaucrat::signForm(Form &f)
{
    if (f.getSigned() == true)
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << this->_name << "'s level isn't high enough." << std::endl; 
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return (out);
}