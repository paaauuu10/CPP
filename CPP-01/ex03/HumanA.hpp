#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon  &_arma;
        std::string _name;
    public: 
        HumanA(std::string _type, Weapon &_arma);
        ~HumanA(void);
        void attack(void);
};

#endif