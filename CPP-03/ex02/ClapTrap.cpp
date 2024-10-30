#include "ClapTrap.hpp" 

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
    if (name.empty())
        this->_name = "(null)";
    else
        this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl; 
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
};
void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " can´t attack because is dead.";
    else
        std::cout << "ClapTrap " << this->_name << " doesn´t have enought energy points to attack" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    bool flag = true;
    if (this->_hitPoints <= 0)
    {
        std::cout << this->_name << " is already dead" << std::endl;
        flag = false;
    }
    else if(this->_hitPoints > amount)
        this->_hitPoints -= amount;
    else if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    if (flag)
    {
        std::cout << this->_name << " has been attacked and has lost " << amount << " hit points. ";
		std::cout << "Now, " << this->_name << " has " << this->_hitPoints << " hit points." << std::endl;
        if (this->_hitPoints == 0)
            std::cout << this->_name << " is now dead!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_hitPoints += amount;
        std::cout << this->_name << " has been repaired and has won " << amount << " hit points. ";
		std::cout << "Now, " << this->_name << " has " << this->_hitPoints << " hit points." << std::endl;
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << this->_name << "can´t be repaired because is dead.";
    else
        std::cout << this->_name << "doesn´t have enought energy points to be repaired" << std::endl;
}

unsigned int ClapTrap::getAttackDamage()
{
    return (this->_attackDamage);
}
void    ClapTrap::setAttackDamage(unsigned int damage)
{
    this->_attackDamage = damage;
}