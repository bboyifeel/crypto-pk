#include "math_api_pk.h"

/***********************************
	Euler's function

	Returns -1 if a < 1
***********************************/
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
int gcd(int a, int b)
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

	return u[0] > 0 ? u[0] : n + u[0];
	// equal to if u[0] < 0, then return n - std::abs(u[0])
}


/***********************************
	Power Modulo N [p inclusive]
***********************************/
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


/***********************************
	IsPrime
***********************************/
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
			if (powerModuloN(i,n,n) != i)
			{
				return false;
			}
		}
	}
	return true;
}