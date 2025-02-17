#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>{

    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif