/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 13:30:04 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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

