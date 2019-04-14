#include "tests.h"
#include "rsa_light.h"
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
	tests::expmod();			std::cout << std::endl;
}


void lab3()
{
	uint64_t p;
	uint64_t q;
	uint64_t e;
	uint64_t d;
	int length = 30;
	keygen(p, q, e, d, length);

	uint64_t n 			= p * q;

	uint64_t m 			= 123452;
	uint64_t c 			= RSAencrypt(m, e, n);
	uint64_t decrypted 	= RSAdecrypt(c, d, n);

	std::cout << "Message: " 	<< m 			<< std::endl;
	std::cout << "Cyphertext: "	<< c 			<< std::endl;
	std::cout << "Decrypted: " 	<< decrypted 	<< std::endl;
}


int main()
{
	lab3();
	return 0;
}