#include "Span.hpp"
#include <iostream>
#include <vector>

void testEmptySpan()
{
    Span sp(7);
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testBasicSpan()
{
    Span sp(7);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(1);
        sp.addNumber(-10);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // 27
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testOverfillSpan()
{
    Span sp(7);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(1);
        sp.addNumber(-10);
        sp.addNumber(0); // Excepción esperada
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testLargeSpan()
{
    Span s(1500);
    std::vector<int> vec;
    for (int i = 0; i < 1500; i++)
    {
        vec.push_back(i * 23);
    }
    try
    {
        s.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << s.shortestSpan() << std::endl; // 23
        std::cout << "Longest Span: " << s.longestSpan() << std::endl;   // 34477
        s.addNumber(42); // Excepción esperada
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "\nTesting empty Span:" << std::endl;
    testEmptySpan();

    std::cout << "\nTesting basic Span:" << std::endl;
    testBasicSpan();

    std::cout << "\nTesting overfilled Span:" << std::endl;
    testOverfillSpan();

    std::cout << "\nTesting large Span:" << std::endl;
    testLargeSpan();

    return 0;
}