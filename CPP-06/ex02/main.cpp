#include "Base.hpp"
#include <cstdlib> 

int main(){    
    srand(time(0));
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = generate();

	std::cout << std::endl << "Identificacion by pointer :" << std::endl << std::endl;
	std::cout << "Base 1 : ";
	identify(base1);
	std::cout << "Base 2 : ";
	identify(base2);
	std::cout << "Base 3 : ";
	identify(base3);
	std::cout << "Base 4 : ";
	identify(base4);
	std::cout << std::endl << "Identification by reference :" << std::endl << std::endl;
	std::cout << "Base 1 : ";
	identify(*base1);
	std::cout << "Base 2 : ";
	identify(*base2);
	std::cout << "Base 3 : ";
	identify(*base3);
	std::cout << "Base 4 : ";
	identify(*base4);
	delete base1;
	delete base2;
	delete base3;
	delete base4;

	return 0;
}