#include <iostream>
#include "MutantStack.hpp"
#include <string>

int main() {
    std::cout << "=== Pruebas con MutantStack<int> ===" << std::endl;
    MutantStack<int> mstack;
    
    // Inserting elements to stack
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    
    std::cout << "Stack size: " << mstack.size() << std::endl;
    std::cout << "Stack top: " << mstack.top() << std::endl;
    
    // Iterating the stack
    std::cout << "Stack:elements" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Trying to pop
    std::cout << "\nPoping element..." << std::endl;
    mstack.pop();
    std::cout << "New stack size: " << mstack.size() << std::endl;
    std::cout << "New stack top: " << mstack.top() << std::endl;
    
    // Copy constructor
    MutantStack<int> copyStack(mstack);
    std::cout << "\nCopy constructor:" << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Assignment operator
    MutantStack<int> assignStack;
    assignStack = mstack;
    std::cout << "\nAssignment operator" << std::endl;
    for (MutantStack<int>::iterator it = assignStack.begin(); it != assignStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Adding more elements
    std::cout << "\nAdding elements..." << std::endl;
    mstack.push(60);
    mstack.push(70);
    std::cout << "Actual stack: " << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Cleaning stack
    std::cout << "\nCleaning stack" << std::endl;
    while (!mstack.empty()) {
        std::cout << "Cleaning:  " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "Is the sstack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
    
    // Trying with strings
    std::cout << "\n=== Trying MutantStack<std::string> ===" << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("C++");
    
    std::cout << "Stack size: " << sstack.size() << std::endl;
    std::cout << "Stack elements:" << std::endl;
    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}
