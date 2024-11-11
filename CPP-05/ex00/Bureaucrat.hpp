/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:36:21 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/11 16:28:06 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>


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