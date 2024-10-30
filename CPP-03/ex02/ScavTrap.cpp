#include "ScavTrap.hpp" 

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    if (name.empty())
        this->_name = "(null)";
    else
        this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl; 
    *this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target) 
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " can't attack because it is dead." << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points to attack." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << this->_name << " is now in Gate Keeper mode." << std::endl;
}

