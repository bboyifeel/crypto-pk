#include "pk_math_api.h"

std::map<int,int> factor(int n)
{
	std::map<int,int> 	factorization;
	
	if (!n)
	{
		factorization[0] = 0;
		return factorization;
	}

	std::vector<bool> prime(n + 1,true);
	
	for(int i = 2; i*i < prime.size(); i++)
	{
		for(int j = i*i; j < prime.size(); j += i)
		{
			prime[j] = false;
		}
	}

	int divisor = 0;
	for (int i = 2; i < prime.size(); i++)
	{
		if(!prime[i])
			continue;
		
		divisor = i;
		while((n / divisor) == ((double)n / divisor))
		{
			if(divisor == i && factorization.find(divisor) == factorization.end())
			{
				factorization[i] = 0;
			}
			
			factorization[i]++;
			divisor *= divisor;
		}
	}

	return factorization;
}