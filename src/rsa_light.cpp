#include "rsa_light.h"
#include "math_api_pk.h"

#include <iostream>
#include <random>
#include <chrono>
#include <gmpxx.h>
#include <string>
#include <sstream>

#include "tests.h"

mpz_class mpz_inverse(uint64_t ua, uint64_t um);

void keygen(uint64_t& p, uint64_t& q, uint64_t& e, uint64_t& d, int length)
{
	int upperBound = pow(2,length + 1) - 1;
	//std::cout << upperBound << std::endl;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine 			eng{seed};
	std::uniform_int_distribution<int> 	disPQ(1, upperBound);


	//std::cout << "Generating p" << std::endl;
	while(true)
	{
		p = disPQ(eng);	
		//std::cout << p << std::endl;
		if(isPrime(p))
		{
			//std::cout << "prime number has been found" << std::endl;
			break;
		}
	}
	
	//std::cout << "Generating q" << std::endl;
	while(true)
	{
		q = disPQ(eng);	
		//std::cout << q << std::endl;
		if(isPrime(q))
		{
			//std::cout << "prime number has been found" << std::endl;
			break;
		}
	}

	uint64_t n 	= p * q;
	uint64_t f 	= (p - 1) * (q - 1);

	std::uniform_int_distribution<int> 	disE(1, f - 1);
	
	//std::cout << "Generating e" << std::endl;
	while(true)
	{
		e = disE(eng);
		e %= f;
		//std::cout << e << std::endl;
		if(gcd(e, f) == 1)
		{
			//std::cout << "e such that gcd(e,f) has been found" << std::endl;
			break;
		}
	}

	//std::cout << "Generating d" << std::endl;
	std::istringstream iss(mpz_inverse(e, f).get_str());
	iss >> d;
	
	std::cout << "n " << n 	<< std::endl;
	std::cout << "f " << f 	<< std::endl;
	std::cout << "e " << e 	<< std::endl;
	std::cout << "d " << d 	<< std::endl;
}


mpz_class mpz_inverse(uint64_t ua, uint64_t um)
{
	if (::gcd(ua, um) != 1)
		return -1;

	if (um == 1)
		return 0;

	mpz_class a { std::to_string(ua) };
	mpz_class m { std::to_string(um) };
	mpz_class m0 	= m; 
	mpz_class y 	= 0;
	mpz_class x 	= 1;	 
		
	while (a > 1) 
	{
		// q is quotient 
		mpz_class q = a / m; 
		mpz_class t = m; 
  
		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t; 
		t = y; 
  
		// Update y and x 
		y = x - q * y; 
		x = t; 
	} 
  
	// Make x positive 
	if (x < 0) 
	   x += m0; 
  
	return x; 
}


mpz_class gmpExpmod(mpz_class base, mpz_class exp, mpz_class n)
{
	mpz_class result = 1;

	while (exp > 0)
	{
		if (exp % 2 == 1)
			result = (result * base) % n;
		exp = exp >> 1;
		base = (base * base) % n;
	}

	return result;
}


uint64_t RSAencrypt(uint64_t m, uint64_t e, uint64_t n)
{
	mpz_class gmpM, gmpE, gmpN;
	gmpM = std::to_string(m);
	gmpE = std::to_string(e);
	gmpN = std::to_string(n);

	uint64_t result;
	std::istringstream iss(gmpExpmod(gmpM, gmpE, gmpN).get_str());
	iss >> result;

	return result;
}


uint64_t RSAdecrypt(uint64_t c, uint64_t d, uint64_t n)
{
	mpz_class gmpC, gmpD, gmpN;
	gmpC = std::to_string(c);
	gmpD = std::to_string(d);
	gmpN = std::to_string(n);

	uint64_t result;
	std::istringstream iss(gmpExpmod(gmpC, gmpD, gmpN).get_str());
	iss >> result;

	return result;
}