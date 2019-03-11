#include "pk_math_api.h"
#include <iostream>
#include <cmath>

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}


void gcdTest()
{
	int a = 12;
	int b = 15;
	
	int gcdAB = gcd(a, b);
	std::cout << "gcd(" <<a << "," << b << ") = " << gcdAB << std::endl;
}