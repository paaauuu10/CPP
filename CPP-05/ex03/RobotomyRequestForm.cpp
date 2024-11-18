/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:24 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 15:23:03 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
   
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 25, 5)
{
    std::cout << "RobotomyRequestForm deafult constructor" << std::endl;        
    this->_target = "Undefined";
}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 25, 5)
{
    std::cout << "RobotomyRequestForm target constructor" << std::endl;
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    (*this) = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm copy assignment called" << std::endl;
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destrucor called" << std::endl;
}

void    RobotomyRequestForm::executeAction()const
{
    std::cout << "Making some drilling noises..." << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "ERROR: Robotomy has failed!" << std::endl;
        
}
        
std::string RobotomyRequestForm::getTarget()
{
    return (this->_target);
}
void    RobotomyRequestForm::setTarget(std::string target)
{
    this->_target = target;
}