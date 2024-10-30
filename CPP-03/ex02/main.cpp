#include "ClapTrap.hpp" 
#include "ScavTrap.hpp"
#include "FragTrap.hpp" 


int main()
{
 
    ScavTrap D("D");
    std::cout << std::endl;
    ClapTrap J("J");
    std::cout << std::endl;
    FragTrap P("P");
    std::cout << std::endl;
    
    D.attack("P");
    P.takeDamage(D.getAttackDamage());
    J.attack("D");
    D.takeDamage(J.getAttackDamage());
    std::cout << std::endl;

    D.guardGate();
    P.highFivesGuys();
    std::cout << std::endl;


    return (0);
}
