/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:19 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:15 by pbotargu         ###   ########.fr       */
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

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception &e)
    {
        std::cout << this->getName() << " can't execute form because: " << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return (out);
}