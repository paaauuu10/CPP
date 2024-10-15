#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string zombie_name); // CONSTRUCTOR
        ~Zombie(); // DESTRUCTOR
        void announce(void);
};

#endif
