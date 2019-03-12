#include "pk_math_api.h"

// Chinese Remainder
// returns -1 in case if gcd(n1,n2) != 1
int restechinois(int a, int p, int b, int q)
{
	if (gcd(p, q) != 1)
		return -1;

	int z = 0;
	//part 1
	z += a * q * inverse(q, p);
	//part 2
	z += b * p * inverse(p, q);
	return z % (p*q);
}