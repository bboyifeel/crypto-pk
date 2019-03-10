#include "pk_math_api.h"
#include <iostream>
#include <cmath>

// Chinese Remainder
// returns -1 in case if gcd(n1,n2) != 1
int restechinois(int a, int p, int b, int q)
{
	if (gcdEuclid(p, q) != 1)
		return -1;

	int z = 0;
	//part 1
	z += a * q * inverse(q, p);
	//part 2
	z += b * p * inverse(p, q);
	return z % (p*q);
}

void restechinoisTest()
{
	int a = 4;
	int p = 5;
	int b = 3;
	int q = 7;
	
	int z = restechinois(a,p,b,q);
	std::cout << "Chinese remainder = " << z << std::endl;
}