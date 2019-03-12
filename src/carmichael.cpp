#include "pk_math_api.h"

// p [inclusive]
int powerModuloN(int b, int p, int n)
{
	int result = b;
	for (int i = 2; i <= p; i++)
	{
		result *= b;
		result %= n;
	}
	return result;
}

bool isPrime(int n)
{
	std::vector<bool> prime(n + 1, true);
	
	for(int i = 2; i*i < prime.size(); i++)
	{
		for(int j = i*i; j < prime.size(); j += i)
		{
			prime[j] = false;
		}
	}

	return prime[n];
}

// n has to be composite
// this function is not checking if number is composit
bool isCarmichaelNumber(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (gcd(n,i) == 1)
		{
			if (powerModuloN(i,n,n) != i)
			{
				return false;
			}
		}
	}
	return true;
}

// Carmichael numbers up to n [excluding]
std::vector<int> carmichaelNumbers(int n)
{
	std::vector<int> result;

	for (int i = 2; i < n; i++)
	{
		if(!isPrime(i))
		{
			if(isCarmichaelNumber(i))
			{
				result.push_back(i);
			}
		}
	}
	
	return result;
}