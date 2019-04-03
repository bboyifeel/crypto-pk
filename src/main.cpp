#include "tests.h"
#include <iostream>

void lab1()
{
	tests::gcd(); 				std::cout << std::endl;
	tests::factor();			std::cout << std::endl;
	tests::inverse();			std::cout << std::endl;
	tests::restechinois();		std::cout << std::endl;
	tests::euler();				std::cout << std::endl;
	tests::carmicahelNumbers();	std::cout << std::endl;
}


void lab2()
{
	tests::bigIntAddition();	std::cout << std::endl;
	tests::FibonacciSequence();
}


int main()
{
	lab2();
	return 0;
}