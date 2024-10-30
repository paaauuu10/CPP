#include "FragTrap.hpp" 

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    if (name.empty())
        this->_name = "(null)";
    else
        this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl; 
    *this = other;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
};

void FragTrap::highFivesGuys(void)
{
    std::cout << this->_name << " is asking you to give a high five" << std::endl;
}

