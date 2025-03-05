#include "BitcoinExchange.hpp"

double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    if (!(iss >> result)) {
        throw std::invalid_argument("Error: No se pudo convertir a double");
    }

    //Checks if there are extra non-numeric characters
    char extra;
    if (iss >> extra) {
        throw std::invalid_argument("Error: La cadena contiene caracteres no numéricos");
    }

    return result;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

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
    // Opening data.csv and saving it on container map -> ddbb

    std::string str = "data.csv";
    std::ifstream ddbb(str.c_str());

    if (!ddbb.is_open()){
        throw std::invalid_argument("Error: File .csv not found");
    }
    std::string line;
    std::getline(ddbb, line); // We are omitting header
    while(std::getline(ddbb, line)){
        std::string::size_type position = line.find(",");
        if (position != std::string::npos){
            std::string date = line.substr(0, position);
            double price = stringToDouble(line.substr(position + 1, std::string::npos));
            data.insert(std::make_pair(date, price));
        }
    }
    ddbb.close();
}

BitcoinExchange::~BitcoinExchange(){}

void    BitcoinExchange::openFile(std::string name){
    
    std::ifstream   input(name.c_str());

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
            double n_btc = stringToDouble(line.substr(position + 1, std::string::npos));
            if (n_btc > 1000){
                std::cout << "Error: too large number." << std::endl;
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
