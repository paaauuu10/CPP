#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_arma = nullptr;
}
HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
    if (!this->_arma->getType().empty())
        std::cout << this->_name << " attacks with a " << this->_arma->getType() << std::endl;
    else
        std::cout << this->_name << " doesn't have any weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &arma)
{
    this->_arma = &arma;
}