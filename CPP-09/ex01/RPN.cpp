#include "RPN.hpp"

RPN::RPN(){}
		
RPN::RPN(const RPN &other){ *this = other; }

RPN &RPN::operator=(const RPN &other){
    if (this != &other)
        this->stack = other.stack;
    return (*this);
}

RPN::~RPN(){}

void    RPN::polishOperation(std::string polish){

    int a;
    int b;

    for (size_t i = 0; i < polish.length(); i++){
        if (isdigit(polish[i]))
    }
}