/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:21 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 15:30:28 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"


class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName()const;
        int getGrade()const;
        
        void incrementGrade();
        void decrementGrade();

        void setGrade(int grade);

        void signForm(AForm &f);
        void executeForm(AForm const &form);
        
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char  *what(void) const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif