#include "pk_math_api.h"
#include "prints.h"

void printFactorizationMap(std::map<int,int> m)
{
	for (auto const& item: m)
	{
		std::cout << "(" << item.first << "," << item.second << ")" << " ";
	}
	std::cout << std::endl;
}

void gcdTest()
{
	int a = 12;
	int b = 15;
	
	int gcdAB = gcd(a, b);
	std::cout << "gcd(" <<a << "," << b << ") = " << gcdAB << std::endl;
}

void factorTest()
{
	int a = 150;
	std::map<int,int> factorization = factor(a);
	printFactorizationMap(factorization);
}

void inverseTest()
{
	int a = 2;
	int n = 6;
	
	int inverseElement = inverse(a,n);
	if (inverseElement > 0)
	{
		std::cout << "inverse = " << inverseElement << std::endl;
	}
	else
	{
		std::cout << a << " has no inverse element modulo " << n << std::endl;
	}
}

void restechinoisTest()
{
	int a = 4;
	int p = 5;
	int b = 3;
	int q = 7;
	
	int z = restechinois(a,p,b,q);
	std::cout << "Chinese remainder = " << z << std::endl;
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

void isCarmicahelNumberTest()
{
	int b = 561;
	std::cout << b << " carmicahel number? " << isCarmichaelNumber(b) << std::endl;
}

void carmicahelNumbersTest()
{
	int n = 10000;
	std::cout << "Carmichael Numbers up to " << n << std::endl;
	printVector(carmichaelNumbers(n));
	std::cout << std::endl;
}

void isPrimeTest()
{
	int n = 13;
	std::cout << n << " is Prime? " << isPrime(n) << std::endl;
	n = 14;
	std::cout << n << " is Prime? " << isPrime(n) << std::endl;
	n = 561;
	std::cout << n << " is Prime? " << isPrime(n) << std::endl;
	n = 100001;
	std::cout << n << " is Prime? " << isPrime(n) << std::endl;
}