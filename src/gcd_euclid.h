#ifndef CRYPTO_PK_GCD_EUCLID
#define CRYPTO_PK_GCD_EUCLID

int 	gcdEuclid(int a, int b, bool log = false);
void 	gcdEuclidTest();
void 	printEuclidsEquasion(int r[3], int q);

#endif