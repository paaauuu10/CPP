#include "Zombie.hpp"

// Declaraciones de las funciones externas
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    
    int N = 2;
    Zombie *Zombie_horde = zombieHorde(N, "Pau");
    for (int i = 0; i < N; i++)
        Zombie_horde[i].announce();
    delete [] Zombie_horde;
    return (0);
}