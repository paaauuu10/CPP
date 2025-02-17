#include "MutantStack.hpp"
// Implementación de MutantStack

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
