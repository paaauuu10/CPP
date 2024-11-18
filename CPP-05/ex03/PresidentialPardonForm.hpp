/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:22 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/14 10:17:42 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        void    executeAction()const;
        
        std::string getTarget();
        void    setTarget(std::string target);
        
};