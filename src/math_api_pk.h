#ifndef CRYPTO_MATH_API_PK
#define CRYPTO_MATH_API_PK

#include <map>
#include <vector>
#include <cmath>


/***********************************
	GCD
***********************************/
int 				gcd(int a, int b);


/***********************************
	Factorization
***********************************/
std::map<int,int> 	factor(int n);


/***********************************
	Multiplicative inverse (using Euclid's extended algorithm)

	returns -1 in case if it doesn't exist
***********************************/
int 				inverse(int a, int n);


/***********************************
	Chinese Remainder

	returns -1 in case if gcd(n1,n2) != 1
***********************************/
int 				restechinois(int a1, int n1, int a2, int n2);


/***********************************
	Euler's function

	Returns -1 if a < 1
***********************************/
int 				euler(int a);


/***********************************
	Carmichael numbers up to n [excluding]
***********************************/
std::vector<int> 	carmichaelNumbers(int n);


/***********************************
	Power Modulo N [p inclusive]
***********************************/
int 				powerModuloN(int b, int p, int n);


/***********************************
	IsPrime
***********************************/
bool 				isPrime(int n);


/***********************************
	bigInt
***********************************/
struct bigInt
{
	bool			sign;
	unsigned short	size;
	unsigned char*	arr;
};


/***********************************
	Addition of two Big Integers
***********************************/
bigInt 		bigIntAddition(bigInt a, bigInt b);


/***********************************
	Addition of two positive Big Integers
***********************************/
bigInt 		operationAddition(bigInt a, bigInt b);


/***********************************
	Subtraction of two positive Big Integers
	a > b
***********************************/
bigInt 		operationSubtraction(bigInt a, bigInt b);


/***********************************
	Compares a and b
	returns true if a >= b
***********************************/
bool 		bigIntIsEqualBigger(bigInt a, bigInt b);


typedef void(*printFunc)(bigInt);
/***********************************
	Compares a Fibonacci term number n
***********************************/
bigInt 		FibonacciSequence(unsigned int n);


/***********************************
	Multiplication of two Big Integers
***********************************/
bigInt 		bigIntMultiply(bigInt a, bigInt b);

#endif //CRYPTO_MATH_API_PK