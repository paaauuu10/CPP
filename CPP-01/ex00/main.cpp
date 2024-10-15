#include "Zombie.hpp"

// Declaraciones de las funciones externas
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    
    std::string zombies[5] = {"pbotargu", "Pau", "Botargues", "Julio", "pbj"};

    Zombie* heapZombie = newZombie("ZombieMemory");
    heapZombie->announce();
    delete heapZombie;

    for (int i = 0; i < 5; i++)
        randomChump(zombies[i]);
    return 0;
}