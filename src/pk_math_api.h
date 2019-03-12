#ifndef CRYPTO_PK_GCD_EUCLID
#define CRYPTO_PK_GCD_EUCLID

#include <map>
#include <vector>
#include <cmath>

int 				gcd(int a, int b);

std::map<int,int> 	factor(int n);

// multiplicative inverse using Euclid's extended algorithm
// returns -1 in case if it doesn't exist
int 				inverse(int a, int n);

// Chinese Remainder
// returns -1 in case if gcd(n1,n2) != 1
int 				restechinois(int a1, int n1, int a2, int n2);

// Euler's function. Returns -1 if a < 1
int 				euler(int a);

// Carmichael numbers up to n [excluding]
std::vector<int> 	carmichaelNumbers(int n);

// n has to be composite
// this function is not checking if number is composit
bool 				isCarmichaelNumber(int n);

bool 				isPrime(int n);

#endif