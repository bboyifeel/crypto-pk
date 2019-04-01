#include <vector>
#include <iostream>
#include "tests.h"


template<class T>
void 	printVector(std::vector<T> vec)
{
	std::cout << "[ "; 
	for(auto item: vec)
	{
		std::cout << item << " ";
	}
	std::cout << "]";
	std::cout << std::endl;
}
	
	
namespace tests
{
	

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
		std::cout << "factor " << a << std::endl;
		printFactorizationMap(factorization);
	}
	
	
	void inverseTest()
	{
		int a = 5;
		int n = 7;
		
		int inverseElement = inverse(a,n);
		if (inverseElement > 0)
		{
			std::cout << "iverse " << a << " " << n << std::endl;
			std::cout << inverseElement << std::endl;
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
		std::cout << "restechinois " << a << " " << p << " "<< b << " " << q << std::endl;
		std::cout << z << std::endl;
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
}//namespace tests