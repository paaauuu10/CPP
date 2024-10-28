#include "ClapTrap.hpp" 

int main()
{
    ClapTrap P("P");
    ClapTrap D("D");
    ClapTrap J("J");

    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    D.beRepaired(7);
    
    P.setAttackDamage(1);
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());
    P.attack("D");
    D.takeDamage(P.getAttackDamage());

    P.attack("D");
    J.setAttackDamage(9);
    J.attack("D");
    D.takeDamage(J.getAttackDamage());

    return (0);
}
