#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <map>

void printBoolVectro(std::vector<bool> vec)
{
	std::cout << "["; 
	for(auto item: vec)
	{
		std::cout << (item ? 1 : 0);
	}
	std::cout << "]";
	std::cout << std::endl;
}

void printFactorizationMap(std::map<int,int> m)
{
	for (auto const& item: m)
	{
		std::cout << "(" << item.first << "," << item.second << ")" << " ";
	}
	std::cout << std::endl;
}

std::map<int,int> factor(int _n)
{
	std::map<int,int> 	factorization;
	
	if (!_n)
	{
		factorization[0] = 0;
		return factorization;
	}

	std::vector<bool> prime(_n + 1,true);
	
	for(int i = 2; i*i < prime.size(); i++)
	{
		for(int j = i*i; j < prime.size(); j += i)
		{
			prime[j] = false;
		}
	}
	//printBoolVectro(prime);

	int 				divisor = 0;
	for (int i = 2; i < prime.size(); i++)
	{
		if(!prime[i])
			continue;
		
		divisor = i;
		while((_n / divisor) == ((double)_n / divisor))
		{
			if(divisor == i && factorization.find(divisor) == factorization.end())
			{
				//std::cout << _n << " is divisible by " << divisor << std::endl;
				factorization[i] = 0;
			}
			
			factorization[i]++;
			divisor *= divisor;
		}
	}
	return factorization;
}

int main()
{
	int a = 0;
	std::map<int,int> factorization = factor(a);
	printFactorizationMap(factorization);

	return 0;
}