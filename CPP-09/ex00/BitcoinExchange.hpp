#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange{
    private:
        std::map<std::string, double>   data;
    
    public: 
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

        void    openFile(std::string name);
        void printResult(const std::string& date, double n_btc, double rate);
};



#endif