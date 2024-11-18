/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/14 10:21:21 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
   
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm deafult constructor" << std::endl;        
    this->_target = "Undefined";
}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm target constructor" << std::endl;
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    (*this) = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy assignment called" << std::endl;
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destrucor called" << std::endl;
}

void    PresidentialPardonForm::executeAction()const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
        
std::string PresidentialPardonForm::getTarget()
{
    return (this->_target);
}
void    PresidentialPardonForm::setTarget(std::string target)
{
    this->_target = target;
}