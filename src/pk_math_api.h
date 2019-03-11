#ifndef CRYPTO_PK_GCD_EUCLID
#define CRYPTO_PK_GCD_EUCLID

#include <map>

int 				gcd(int a, int b);

std::map<int,int> 	factor(int n, bool log = false);

// multiplicative inverse using Euclid's extended algorithm
// returns -1 in case if it doesn't exist
int 				inverse(int a, int n);

// Chinese Remainder
// returns -1 in case if gcd(n1,n2) != 1
int 				restechinois(int a1, int n1, int a2, int n2);

// Euler's function. Returns -1 if a < 1
int 				euler(int a);

void 	gcdTest();
void 	factorTest();
void 	inverseTest();
void 	restechinoisTest();
void	eulerTest();

#endif