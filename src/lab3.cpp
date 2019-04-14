#include "math_api_pk.h"
#include <random>
#include <chrono>
#include <iostream>

#define T 200
/***********************************
	IsPrime Fermat test
***********************************/
bool				isPrimeFermat(uint64_t n)
{
	bool result = true;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine 					eng{seed};
	std::uniform_int_distribution<uint64_t> 	dis(2, n - 1);

	uint64_t randomN;
	uint64_t expmodRadomN;
	for (uint64_t i = 0; i < T; i++)
	{
		randomN = dis(eng) % n;
		expmodRadomN = expmod(randomN, n-1, n);
		if (expmodRadomN != 1)
			return false;
	}

	return result;
}