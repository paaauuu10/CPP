#include "ClapTrap.hpp" 

int main()
{
    ClapTrap P("P");
    ClapTrap D("D");
    ClapTrap J("J");

    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    D.beRepaired(7);
    std::cout << std::endl;
   
    for (int i = 0; i < 9; i++)
    {
        P.attack("D");
        D.takeDamage(P.getAttackDamage());
    }

    std::cout << std::endl;
    P.attack("D");
    J.setAttackDamage(17);
    J.attack("D");
    D.takeDamage(J.getAttackDamage());

    P.beRepaired(2);
    D.attack("J");

    std::cout << std::endl;


    return (0);
}
