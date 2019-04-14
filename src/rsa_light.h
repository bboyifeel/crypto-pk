#ifndef CRYPTO_PK_RSA_LIGHT
#define CRYPTO_PK_RSA_LIGHT

#include <cstdint>

void 		keygen(uint64_t& p, uint64_t& q, uint64_t& e, uint64_t& d, int length);


uint64_t	RSAencrypt(uint64_t m, uint64_t e, uint64_t n);


uint64_t 	RSAdecrypt(uint64_t c, uint64_t d, uint64_t n);

#endif // CRYPTO_PK_RSA_LIGHT