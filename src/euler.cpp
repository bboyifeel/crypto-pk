#include "pk_math_api.h"
#include <iostream>
#include <cmath>

// Euler's function. Returns -1 if a < 1
int euler(int a)
{
	if (a < 1)
		return -1;
	return 0;
}

void eulerTest()
{
	int a = 0;
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