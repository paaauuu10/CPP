/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/13 16:35:04 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default Form"), _gradeSign(150), _gradeExec(150)
{
    std::cout << "AForm default constructor called" << std::endl;
    this->_signed = false;
}
AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "AForm name constructor called" << std::endl;
    if (this->_gradeSign > 150 || this->_gradeExec > 150)
        throw (AForm::GradeTooLowException());
    else if (this->_gradeSign < 1 || this->_gradeExec < 1)
        throw (AForm::GradeTooHighException());
    else
        this->_signed = false;
}
AForm::AForm(const AForm &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    std::cout << "AForm Copy construcor called" << std::endl;
    //CAL COPIAR EL BOOLEA? REVISAR SUBJECT
    // this->_signed = other._signed;
}
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm Operator '=' called" << std::endl;
    if (this != &other)
        this->_signed = other._signed;
    return (*this);   
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
};

void    AForm::beSigned(const Bureaucrat &Bureau)
{
    if (Bureau.getGrade() <= this->_gradeSign)
        this->_signed = true;
}
const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Too high grade!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
    return ("Form is not signed!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Too low grade!");
}

bool AForm::getSigned(void)const
{
    return (this->_signed);
}

std::string AForm::getName()const
{
    return (this->_name);
}

int AForm::getGradeS()const
{
    return (this->_gradeSign);
}

int AForm::getGradeE()const
{
    return (this->_gradeExec);
}

void AForm::execute(const Bureaucrat &executor)const
{
    if (!this->_signed)
        throw(AForm::FormNotSignedException());
    else if (executor.getGrade() > this->_gradeExec)
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << executor.getName() << " executed " << this->_name << std::endl;
        //falta funcio executar!
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << ", form grade required to sign is " << f.getGradeS()
		<< " and grade required to execute is " << f.getGradeE() << ". " << std::endl;
	if (f.getSigned())
		out << "It is already signed" << std::endl;
	else
		out << "It hasn't signed yet" << std::endl;
	return (out);
}

