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
	tests::FibonacciSequence();	std::cout << std::endl;
	tests::bigIntMultiply();	std::cout << std::endl;
	tests::bigIntFactorial();	std::cout << std::endl;
}


int main()
{
	lab2();
	return 0;
}