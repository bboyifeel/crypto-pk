#include "pk_math_api.h"
#include <iostream>
#include <cmath>

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

void eulerTest()
{
	int a = 10;
	int eulerVal = euler(a);
	if (eulerVal != -1)
	{
		std::cout << "Euler function of " << a << " = " << eulerVal << std::endl;
	}
	else
	{
		std::cout << "Euler's function accepts values strictly greatter than 0" << std::endl;
	}
}