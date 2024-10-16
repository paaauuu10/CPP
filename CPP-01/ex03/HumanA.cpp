#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &arma): _arma(arma), _name(name)
{}

HumanA::~HumanA(void)
{}
void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with a " << this->_arma.getType() << std::endl;
}