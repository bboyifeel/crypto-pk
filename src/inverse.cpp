#include "pk_math_api.h"

// multiplicative inverse using Euclid's extended algorithm
// returns -1 in case if it doesn't exist
int inverse(int a, int n)
{
	if (gcd(a, n) != 1)
		return -1;

	int u[3] = { 1, 0, 0};

	int r[3] = { a, n, 0};
	int q;
	
	do
	{
		q 	 = r[0] / r[1];
	
		u[2] = u[0] - q * u[1];
		r[2] = r[0] - q * r[1];

		u[0] = u[1];
		u[1] = u[2];

		r[0] = r[1];
		r[1] = r[2];
		r[2] = 0;
	
	} while(r[1] != 0);

	return u[0] > 0 ? u[0] : n + u[0]; // equal to if u[0] < 0, then return n - std::abs(u[0])
}