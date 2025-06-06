#include "ClapTrap.hpp" 
#include "ScavTrap.hpp"

int main()
{
 
    ScavTrap D("D");
    ClapTrap J("J");
    std::cout << std::endl;
    ScavTrap P("P");
    std::cout << std::endl;
    
    D.attack("P");
    P.takeDamage(D.getAttackDamage());
    J.attack("D");
    D.takeDamage(J.getAttackDamage());
    std::cout << std::endl;

    D.guardGate();
    std::cout << std::endl;


    return (0);
}
