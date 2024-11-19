/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/19 12:31:18 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default Form"), _gradeSign(150), _gradeExec(150)
{
    std::cout << "Form default constructor called" << std::endl;
    this->_signed = false;
}
Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "Form name constructor called" << std::endl;
    if (this->_gradeSign > 150 || this->_gradeExec > 150)
        throw (Form::GradeTooLowException());
    else if (this->_gradeSign < 1 || this->_gradeExec < 1)
        throw (Form::GradeTooHighException());
    else
        this->_signed = false;
}
Form::Form(const Form &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    std::cout << "Copy construcor called" << std::endl;
    //CAL COPIAR EL BOOLEA? REVISAR SUBJECT
    // this->_signed = other._signed;
}
Form &Form::operator=(const Form &other)
{
    std::cout << "Operator '=' called" << std::endl;
    if (this != &other)
        this->_signed = other._signed;
    return (*this);   
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
};

void    Form::beSigned(const Bureaucrat &Bureau)
{
    if (Bureau.getGrade() <= this->_gradeSign)
        this->_signed = true;
}
const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Too high grade!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Too low grade!");
}

bool Form::getSigned(void)const
{
    return (this->_signed);
}

std::string Form::getName()const
{
    return (this->_name);
}

int Form::getGradeS()const
{
    return (this->_gradeSign);
}

int Form::getGradeE()const
{
    return (this->_gradeExec);
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", form grade required to sign is " << f.getGradeS()
		<< " and grade required to execute is " << f.getGradeE() << ". " << std::endl;
	if (f.getSigned())
		out << "It has already been signed." << std::endl;
	else
		out << "It hasn't been signed yet." << std::endl;
	return (out);
}

