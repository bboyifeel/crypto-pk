#include "tests.h"
#include <iostream>

int main()
{
	tests::gcdTest();
		std::cout << std::endl;
	tests::factorTest();
		std::cout << std::endl;
	tests::inverseTest();
		std::cout << std::endl;
	tests::restechinoisTest();
		std::cout << std::endl;
	tests::eulerTest();
		std::cout << std::endl;
	tests::carmicahelNumbersTest();

	return 0;
}