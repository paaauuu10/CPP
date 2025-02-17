#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
	int i = rand() % 3;

	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (const std::exception& e) {}
}


