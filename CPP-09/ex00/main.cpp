#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Usage: ./btc [filename]" << std::endl;
        return 0;
    }
    
    BitcoinExchange btc;
    btc.openFile(argv[1]);
}