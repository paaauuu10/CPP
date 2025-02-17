#include "Span.hpp"

int main()
{
	Span sp = Span(7);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;//No hay nada, excepción
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(1);
		sp.addNumber(-10);
		std::cout << sp.shortestSpan() << std::endl; //2
		std::cout << sp.longestSpan() << std::endl; //27
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp.addNumber(0); //esta full, excepción
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span s = Span(1500);
	std::vector<int> vec;
	for(int i = 0; i < 1500; i++)
	{
		vec.push_back((i * 23));
	}

	try
	{
		s.addNumbers(vec.begin(), vec.end());
		std::cout << s.shortestSpan() << std::endl; //23
		std::cout << s.longestSpan() << std::endl; //34477
		s.addNumber(42); //esta lleno
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}