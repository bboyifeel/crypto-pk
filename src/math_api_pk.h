#ifndef CRYPTO_MATH_API_PK
#define CRYPTO_MATH_API_PK

#include <map>
#include <vector>
#include <cmath>


/***********************************
	GCD
***********************************/
int 				gcd(uint64_t a, uint64_t b);


/***********************************
	Factorization
***********************************/
std::map<int,int> 	factor(int n);


/***********************************
	Multiplicative inverse (using Euclid's extended algorithm)

	returns -1 in case if it doesn't exist
***********************************/
uint64_t 			inverse(uint64_t a, uint64_t n);


/***********************************
	Chinese Remainder

	returns -1 in case if gcd(n1,n2) != 1
***********************************/
int 				restechinois(int a1, int n1, int a2, int n2);


/***********************************
	Euler's function

	Returns -1 if a < 1
***********************************/
int 				euler(uint64_t a);


/***********************************
	Carmichael numbers up to n [excluding]
***********************************/
std::vector<int> 	carmichaelNumbers(int n);


/***********************************
	Power Modulo N [e inclusive]
***********************************/
uint64_t 			expmod(uint64_t b, uint64_t e, uint64_t n);


/***********************************
	IsPrime
***********************************/
bool 				isPrime(int n);


/***********************************
	IsPrime Fermat test
***********************************/
bool				isPrimeFermat(uint64_t n);


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


/***********************************
	Factorial of Big Integers
***********************************/
bigInt 		bigIntFactorial(unsigned int n);


/***********************************
	Converter Int to Big Int
***********************************/
bigInt 		intToBigInt(uint64_t n);


/***********************************
	Converter Int to Big Int
***********************************/
uint64_t 	bigIntToInt(bigInt a);


/***********************************
	Power Modulo N [e inclusive]
***********************************/
bigInt 		bigIntExpmod(bigInt b, bigInt e, bigInt n);


/***********************************
	Division by 2
***********************************/
void 		bigIntRightShift(bigInt& e);


/***********************************
	Big Int Mod
	// for positive only
***********************************/
bigInt 		bigIntMod(bigInt e, bigInt modulus);

#endif //CRYPTO_MATH_API_PK