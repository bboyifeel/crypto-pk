#include "pk_math_api.h"

// Euler's function. Returns -1 if a < 1
int euler(int n)
{
	if (n < 1)
		return -1;

	unsigned int result = 1;
	for (int i = 2; i < n; i++)
	{
		if(gcd(n,i) == 1)
			result++;
	}
	return result;
}