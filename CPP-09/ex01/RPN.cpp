#include <iostream>
#include <stack>
#include <limits>

class RPN {
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void polishOperation(std::string polish);

private:
    std::stack<int> stack;
};

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->stack = other.stack;
    return (*this);
}
RPN::~RPN() {}

void RPN::polishOperation(std::string polish) {
    int first;
    int second;
    std::string operators = "+-*/";

    for (size_t i = 0; i < polish.length(); i++) {
        if (isdigit(polish[i]))
            this->stack.push(polish[i] - '0');
        else if (polish[i] == ' ')
            continue;
        else if (operators.find(polish[i]) != std::string::npos) {
            if (stack.size() < 2) {
                std::cout << "Error: Impossible to execute operand with only one number" << std::endl;
                return;
            }
            second = stack.top();
            stack.pop();
            first = stack.top();
            stack.pop();

            // 🚀 Comprobaciones para evitar desbordamiento
            if (polish[i] == '+') {
                if ((second > 0 && first > std::numeric_limits<int>::max() - second) ||
                    (second < 0 && first < std::numeric_limits<int>::min() - second)) {
                    std::cout << "Error: Overflow" << std::endl;
                    return;
                }
                stack.push(first + second);
            }
            else if (polish[i] == '-') {
                if ((second > 0 && first < std::numeric_limits<int>::min() + second) ||
                    (second < 0 && first > std::numeric_limits<int>::max() + second)) {
                    std::cout << "Error: Overflow" << std::endl;
                    return;
                }
                stack.push(first - second);
            }
            else if (polish[i] == '*') {
                if (first != 0 && second != 0) {
                    if (first > 0 && second > 0 && first > std::numeric_limits<int>::max() / second) {
                        std::cout << "Error: Overflow" << std::endl;
                        return;
                    }
                    if (first > 0 && second < 0 && second < std::numeric_limits<int>::min() / first) {
                        std::cout << "Error: Overflow" << std::endl;
                        return;
                    }
                    if (first < 0 && second > 0 && first < std::numeric_limits<int>::min() / second) {
                        std::cout << "Error: Overflow" << std::endl;
                        return;
                    }
                    if (first < 0 && second < 0 && first < std::numeric_limits<int>::max() / second) {
                        std::cout << "Error: Overflow" << std::endl;
                        return;
                    }
                }
                stack.push(first * second);
            }
            else if (polish[i] == '/') {
                if (second == 0) {
                    std::cout << "Error: Impossible to divide by 0" << std::endl;
                    return;
                }
                if (first == std::numeric_limits<int>::min() && second == -1) {
                    std::cout << "Error: Overflow" << std::endl;
                    return;
                }
                stack.push(first / second);
            }
        }
        else {
            std::cout << "Error: [" << polish[i] << "] it isn't a valid parameter." << std::endl;
            return;
        }
    }

    if (stack.size() == 1) {
        first = stack.top();
        std::cout << first << std::endl;
    } else {
        std::cout << "Error: Invalid RPN" << std::endl;
    }
}
