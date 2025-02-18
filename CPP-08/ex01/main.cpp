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
        sp.addNumber(12);
        sp.addNumber(5);
        sp.addNumber(50);
        sp.addNumber(9);
        sp.addNumber(15);
        sp.addNumber(1);
        sp.addNumber(-13);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // 3
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // 63
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
    Span s(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
    {
        vec.push_back(i);
    }
    try
    {
        s.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << s.longestSpan() << std::endl;
        //s.addNumber(42); // Exception
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