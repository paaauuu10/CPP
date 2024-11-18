/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:39 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 17:19:45 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
        
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::presidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::robotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::shrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string stringForm[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*arrayFunctions[3])(std::string) = {&Intern::presidential, &Intern::robotomy, &Intern::shrubbery};

    for (int i = 0; i < 3; i++)
    {
        if (formName == stringForm[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*arrayFunctions[i])(target);
        }
    }
    std::cout << "Form --> " << formName << " doesn't exist!" << std::endl;
    return (NULL);
}