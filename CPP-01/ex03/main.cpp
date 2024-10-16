#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("AK-47");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Broken Bottle");
		bob.attack();
	}
	{
		Weapon club = Weapon("");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("knife");
		jim.attack();
	}
	return 0;
}