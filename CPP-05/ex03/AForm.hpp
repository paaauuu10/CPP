/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:22 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/13 16:30:53 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeSign;
        int const _gradeExec;
        
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        
        std::string getName(void)const;
        bool getSigned(void)const;
        int getGradeS()const;
        int getGradeE()const;

        void beSigned(const Bureaucrat &Bureau);
        void execute(Bureaucrat const &executor)const;
        virtual  void executeAction()const = 0;
        
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

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif