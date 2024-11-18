/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:26 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/18 15:19:27 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void    executeAction()const;
        
        std::string getTarget();
        void    setTarget(std::string target);
        
};