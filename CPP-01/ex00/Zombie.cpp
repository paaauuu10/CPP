#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
    _name = zombie_name;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}