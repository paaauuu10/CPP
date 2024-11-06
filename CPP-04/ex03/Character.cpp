/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:58:49 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/06 11:12:23 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
{
    std::cout << "Character name constructor called" << std::endl;
    this->_name = name;
    for (int i = 0; i < 4; i++) 
        this->_inventory[i] = NULL;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++) 
        delete this->_inventory[i];
}

std::string const & Character::getName() const 
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++) 
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << this->getName() << " has been equiped." << std::endl;
            break;
        }
    }
    std::cout << this->getName() << " inventory's has no empty space."
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}
