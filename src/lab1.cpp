#include "math_api_pk.h"

/***********************************
	Euler's function

	Returns -1 if a < 1
***********************************/
int euler(uint64_t n)
{
	if (n < 1)
		return -1;

	unsigned int result = 1;
	for (uint64_t i = 2; i < n; i++)
	{
		if(gcd(n,i) == 1)
			result++;
	}
	return result;
}


/***********************************
	Carmichael numbers up to n [excluding]
***********************************/
bool 				isCarmichaelNumber(int n);	
std::vector<int> 	carmichaelNumbers(int n)
{
	std::vector<int> result;

	for (int i = 2; i < n; i++)
	{
		if(isCarmichaelNumber(i))
		{
			result.push_back(i);
		}
	}
	
	return result;
}


/***********************************
	Factorization
***********************************/
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


/***********************************
	GCD
***********************************/
int gcd(uint64_t a, uint64_t b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}


/***********************************
	Chinese Remainder

	returns -1 in case if gcd(n1,n2) != 1
***********************************/
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


/***********************************
	Multiplicative inverse (using Euclid's extended algorithm)

	returns -1 in case if it doesn't exist
***********************************/
uint64_t inverse(uint64_t a, uint64_t m)
{
	if (gcd(a, m) != 1)
		return -1;

	uint64_t m0 = m; 
	uint64_t y = 0, x = 1; 
  
	if (m == 1)
		return 0; 
	
	while (a > 1) 
	{
		// q is quotient 
		uint64_t q = a / m; 
		uint64_t t = m; 
  
		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t; 
		t = y; 
  
		// Update y and x 
		y = x - q * y; 
		x = t; 
	} 
  
	// Make x positive 
	if (x < 0) 
	   x += m0; 
  
	return x; 
}


/***********************************
	Power Modulo N [p inclusive]
***********************************/
uint64_t expmod(uint64_t base, uint64_t exponent, uint64_t modulus)
{
	uint64_t result = 1;

	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}

	return result;
}


/***********************************
	IsPrime
***********************************/
bool isPrime(int num)
{
	if (num <= 3)
	{
		return num > 1;
	}
	else if (num % 2 == 0 || num % 3 == 0)
	{
		return false;
	}
	else
	{
		for (int i = 5; i * i <= num; i += 2)
		{
			if (num % i == 0 || num % (i + 2) == 0)
			{
				return false;
			}
		}
		return true;
	}
}


/***********************************
	Is Carmichael Number 
***********************************/
bool isCarmichaelNumber(int n)
{
	if (isPrime(n))
		return false;

	for (int i = 2; i < n; i++)
	{
		if (gcd(n,i) == 1)
		{
			if (expmod(i,n,n) != i)
			{
				return false;
			}
		}
	}
	return true;
}