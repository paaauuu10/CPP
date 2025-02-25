#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Usage: ./RPN [string -> polish operation]" << std::endl;
        return 0;
    }
    RPN polish;
    polish.polishOperation(argv[1]);
    
    return (0);
}