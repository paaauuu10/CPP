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

    int first;
    int second;
    std::string operators = "+-*/";

    for (size_t i = 0; i < polish.length(); i++){
        if (isdigit(polish[i]))
            this->stack.push(polish[i] - '0');
        else if (polish[i] == ' ')
            continue ; 
        else if (operators.find(polish[i]) != std::string::npos){
            if (stack.size() < 2){
                std::cout << "Error" << std::endl << 
                "Impossible to execute operand with only one number." << std::endl;
                return ;
            }
            second = stack.top();
            stack.pop();
            first = stack.top();
            stack.pop();
            if (polish[i] == '+')
                stack.push(first + second);
            else if (polish[i] == '-')
                stack.push(first - second);
            else if (polish[i] == '*')
                stack.push(first * second);
            else if (polish[i] == '/')
                stack.push(first / second);
        }
        else{
            std::cout << "Error" << std::endl << "[" <<
            polish[i] << "] : This is not a valid parameter" << std::endl;
            return ;
        }
    }
    if (stack.size() == 1){
        first = stack.top();
        std::cout << first << std::endl;
    } 
    else
        std::cout << "Error" << std::endl <<
        "The polish operation was impossible to solve!" << std::endl;

}