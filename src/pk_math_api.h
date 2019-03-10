#ifndef CRYPTO_PK_GCD_EUCLID
#define CRYPTO_PK_GCD_EUCLID

#include <map>

int 				gcdEuclid(int a, int b, bool log = false);
std::map<int,int> 	factor(int n, bool log = false);
// multiplicative inverse using Euclid's extended algorithm
// returns -1 in case if it doesn't exist
int 				inverse(int a, int n);

void 	gcdEuclidTest();
void 	factorTest();
void 	inverseTest();

#endif