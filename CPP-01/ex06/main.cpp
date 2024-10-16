#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Need a command" << std::endl;
        return (1);
    }
    Harl    hal;
    std::string complain_cmd(argv[1]);
    hal.complain(complain_cmd);
    return (0);
}