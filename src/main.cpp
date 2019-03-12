#include "tests.h"
#include <iostream>

int main()
{
	gcdTest();
	std::cout << std::endl;
	factorTest();
	std::cout << std::endl;
	inverseTest();
	std::cout << std::endl;
	restechinoisTest();
	std::cout << std::endl;
	eulerTest();
	std::cout << std::endl;
	carmicahelNumbersTest();
	return 0;
}