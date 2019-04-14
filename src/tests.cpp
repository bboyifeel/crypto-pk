#include <vector>
#include <iostream>
#include "tests.h"

namespace prints
{

	template<class T>
	void 	Vector(std::vector<T> vec)
	{
		std::cout << "[ "; 
		for(auto item: vec)
		{
			std::cout << item << " ";
		}
		std::cout << "]";
		std::cout << std::endl;
	}	
	
	
	void FactorizationMap(std::map<int,int> m)
	{
		for (auto const& item: m)
		{
			std::cout << "(" << item.first << "," << item.second << ")" << " ";
		}
		std::cout << std::endl;
	}
	
	
	void	BigInt(::bigInt item)
	{
		if (!item.size)
		{
			std::cout << 0;
			return;
		}

		std::cout << (item.sign ? "" : "-");
		for (int i = item.size - 1; i >= 0; i--)
			std::cout << +item.arr[i];
	}

}// namespace prints

	
namespace tests
{
		
	void gcd()
	{
		int a = 12;
		int b = 15;
		
		int gcdAB = ::gcd(a, b);
		std::cout << "gcd(" <<a << "," << b << ") = " << gcdAB << std::endl;
	}
	
	
	void factor()
	{
		int a = 150;
		std::map<int,int> factorization = ::factor(a);
		std::cout << "factor " << a << std::endl;
		prints::FactorizationMap(factorization);
	}

	
	void inverse()
	{
		uint64_t a = 12;
		uint64_t n = 17;

		uint64_t inverseElement = ::inverse(a,n);
		
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
	
	
	void restechinois()
	{
		int a = 4;
		int p = 5;
		int b = 3;
		int q = 7;
		
		int z = ::restechinois(a,p,b,q);
		std::cout << "restechinois " << a << " " << p << " "<< b << " " << q << std::endl;
		std::cout << z << std::endl;
	}
	
	
	void euler()
	{
		int a = 10;
		int eulerVal = ::euler(a);
		if (eulerVal != -1)
		{
			std::cout << "Euler function of " << a << " = " << eulerVal << std::endl;
		}
		else
		{
			std::cout << "Euler's function accepts values strictly greatter than 0" << std::endl;
		}
	}
	
	
	void carmicahelNumbers()
	{
		int n = 10000;
		std::cout << "Carmichael Numbers up to " << n << std::endl;
		prints::Vector(::carmichaelNumbers(n));
		std::cout << std::endl;
	}
	
	
	void isPrime()
	{
		int n = 13;
		std::cout << n << " is Prime? " << ::isPrime(n) << std::endl;
		n = 14;
		std::cout << n << " is Prime? " << ::isPrime(n) << std::endl;
		n = 561;
		std::cout << n << " is Prime? " << ::isPrime(n) << std::endl;
		n = 100001;
		std::cout << n << " is Prime? " << ::isPrime(n) << std::endl;
	}


	void bigIntAddition()
	{
		// little endian
		unsigned char first[] 	= {0,1,2,3,4,5,6,7,8,9};
		unsigned char second[]	= {0,1,2,3,4,5,6,7,8,9};

		::bigInt a = {.sign = true, .size = sizeof(first) / sizeof(first[0]), .arr = first};
		::bigInt b = {.sign = true, .size = sizeof(second) / sizeof(second[0]), .arr = second};
		::bigInt result = ::bigIntAddition(a, b);
		
		// prints are big endian
		prints::BigInt(a); std::cout << std::endl << " + " << std::endl;
		prints::BigInt(b); std::cout << std::endl << " = " << std::endl;
		prints::BigInt(result); std::cout << std::endl;
		delete result.arr;
	}


	void 	FibonacciSequence()
	{
		prints::BigInt(::FibonacciSequence(101));
		std::cout << std::endl;
	}


	void 	bigIntMultiply()
	{
		// little endian
		unsigned char first[] 	= {0,1,2,3,4,5,6,7,8,9};
		unsigned char second[]	= {0,1,2,3,4,5,6,7,8,9};

		::bigInt a = {.sign = true, .size = sizeof(first) / sizeof(first[0]), .arr = first};
		::bigInt b = {.sign = true, .size = sizeof(second) / sizeof(second[0]), .arr = second};
		::bigInt result = ::bigIntMultiply(a, b);
		
		// prints are big endian
		prints::BigInt(a); 		std::cout << std::endl << " * " << std::endl;
		prints::BigInt(b); 		std::cout << std::endl << " = " << std::endl;
		prints::BigInt(result);	std::cout << std::endl;
		delete result.arr;
	}


	void 		bigIntFactorial()
	{
		prints::BigInt(::bigIntFactorial(40));
		std::cout << std::endl;
	}


	void 		expmod()
	{
		std::cout << "expmod 2342 6762 9343 " << std::endl;
		std::cout << ::expmod(2342, 6762, 9343) << std::endl;
	}


	void 		bigIntToInt()
	{
		// little endian
		unsigned char first[] 	= {0,1,2,3,4,5,6,7,8,9};
		::bigInt a = {.sign = true, .size = sizeof(first) / sizeof(first[0]), .arr = first};
		uint64_t result = ::bigIntToInt(a);
		prints::BigInt(a);
		std::cout << std::endl;
		std::cout << result << std::endl;
	}


	void 		bigIntRightShift()
	{
		unsigned char first[] 	= {0,1,2,3,4,5,6,7,8,9};
		::bigInt a = {.sign = true, .size = sizeof(first) / sizeof(first[0]), .arr = first};
		prints::BigInt(a);
		::bigIntRightShift(a);
		std::cout << std::endl;
		prints::BigInt(a);
	}


	void 		bigIntModulus()
	{
		unsigned char a[] 	= {0,1,2,3,4,5,6,7,8,9};
		unsigned char mod[] = {0,0,2,3,4,5,6,7,8,9};
		::bigInt bigA 	= {.sign = true, .size = sizeof(a) / sizeof(a[0]), .arr = a};
		::bigInt bigMod = {.sign = true, .size = sizeof(mod) / sizeof(mod[0]), .arr = mod};
		::bigInt r = ::bigIntMod(bigA, bigMod);
		prints::BigInt(bigA);	std::cout << std::endl;
		prints::BigInt(bigMod);	std::cout << std::endl;
		prints::BigInt(r);		std::cout << std::endl;
		
		delete r.arr;
	}
}//namespace tests