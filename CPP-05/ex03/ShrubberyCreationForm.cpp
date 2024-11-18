/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:28 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/13 16:42:56 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
   
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm deafult constructor" << std::endl;        
    this->_target = "Undefined";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm target constructor" << std::endl;
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    (*this) = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destrucor called" << std::endl;
}

void    ShrubberyCreationForm::executeAction()const
{
    std::ofstream f;
    
    f.open((this->_target + "_shrubbery").c_str());
    if (f.is_open())
    {
        f << "       ccee88oo\n";
        f << "  C8O8O8Q8PoOb o8oo\n";
        f << " dOB69QO8PdUOpugoO9bD\n";
        f << "CgggbU8OU qOp qOdoUOdcb\n";
        f << "    6OuU  /p u gcoUodpP\n";
        f << "      \\\\//  /douUP\n";
        f << "        \\\\////\n";
        f << "         |||/\\\n";
        f << "         |||\\/\n";
        f << "         |||||\n";
        f << "   .....//||||\\....\n";
        f.close();
    }
    else
        std::cout << "Error opening file" << std::endl;

}
        
std::string ShrubberyCreationForm::getTarget()
{
    return (this->_target);
}
void    ShrubberyCreationForm::setTarget(std::string target)
{
    this->_target = target;
}