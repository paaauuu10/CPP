#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN{
    private:
        std::stack<int> stack;
    
    public:
        RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

        void    polishOperation(std::string polish);

};

#endif