#include "BitcoinExchange.hpp"

// Función para verificar si un año es bisiesto
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Función para verificar si una fecha es válida
bool isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;
    }

    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year)) {
        maxDay = 29;
    }

    return day <= maxDay;
}
BitcoinExchange::BitcoinExchange(){
    // Abrimos el archivo data.csv y lo almacenamos en el containet map -> ddbb

    std::ifstream ddbb("data.csv");

    if (!ddbb.is_open()){
        std::cout << "Error: impossible to open data.csv" << std::endl;
        return;
    }
    std::string line;
    std::getline(ddbb, line); // We are omitting header
    while(std::getline(ddbb, line)){
        std::string::size_type position = line.find(",");
        if (position != std::string::npos){
            std::string date = line.substr(0, position);
            double price = std::stod(line.substr(position + 1, std::string::npos));
            data.insert(std::make_pair(date, price));
        }
    }
    ddbb.close();
}
/*BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
    std::cout << other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    if (&other)
        std::cout << "HOLA";
    return *this;
}*/

BitcoinExchange::~BitcoinExchange(){}

void    BitcoinExchange::openFile(std::string name){
    
    std::ifstream   input(name);

    if (!input.is_open()){
        std::cout << "Error opening input file" << std::endl;
        return ; 
    }
    std::string line;
    std::getline(input, line); // We are omitting header
    while (std::getline(input, line)){
        std::string::size_type position = line.find("|");
        if (position == std::string::npos){
            std::cout << "Error: bad imput ==> " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0, position);
        date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
        if (!isValidDate(date)){
            std::cout << "Error: bad imput ==> " << line << std::endl;
            continue ;
        }
        try{
            double n_btc = std::stod(line.substr(position + 1, std::string::npos));
            if (n_btc > 1000){
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            if (n_btc != std::fabs(n_btc)){
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            std::map<std::string, double>::iterator it = data.lower_bound(date);
            if (it != data.end() && it->first == date) {
                std::cout << date << " ==> " << n_btc << " = " << it->second * n_btc << std::endl;
            } else {
                it--;
                std::cout << date << " ==> " << n_btc << " = " << it->second * n_btc << std::endl;
            }
        }catch(const std::exception& e){
            std::cout << "Error: bad imput ==> " << line << std::endl;
        }
    }
}
