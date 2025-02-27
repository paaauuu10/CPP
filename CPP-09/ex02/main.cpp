#include "PmergeMe.hpp"

bool    validCommand(std::string str){
    for (size_t i = 0; i < str.length(); i++){
        if (!isdigit(str[i]) && !isspace(str[i]))/*hace falta mirar si es un espacio??*/
            return false;
    }
    return true;

}

int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "Usage: ./PmergeMe [string -> int sequence" << std::endl;
        return 0;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; i++){
        if (validCommand(argv[i])){
            std::string input = argv[i];
            vec.push_back(std::atoi(input.c_str()));
        }
        else {
            std::cout << "Error" << std::endl <<
            "Not a positive int sequence." << std::endl;
            return 1;
    }
}

    PmergeMe pmergeme;
    pmergeme.start(vec);
    
    return (0);
}