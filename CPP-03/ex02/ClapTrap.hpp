#ifndef CLAPTRAP__HPP
# define CLAPTRAP__HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints; 
        unsigned int _energyPoints; 
        unsigned int _attackDamage; 
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        unsigned int getAttackDamage();
        void setAttackDamage(unsigned int damage);
};
#endif