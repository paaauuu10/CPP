/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:22 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 13:24:09 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeSign;
        int const _gradeExec;
        
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        
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
#endif