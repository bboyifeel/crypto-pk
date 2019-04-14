#include "math_api_pk.h"
#include <algorithm>
#include <iostream>


/***********************************
	Trims Big Int
***********************************/
void bigIntTrim(bigInt& item)
{
	while(item.size > 0 && !item.arr[item.size-1])
	{
		item.size--;
	}
}

/***********************************
	Compares a and b (unsigned)
	returns true if a >= b
***********************************/
bool bigIntIsEqualBigger(bigInt a, bigInt b)
{
	bigIntTrim(a);
	bigIntTrim(b);

	if (a.size > b.size)
	{
		return true;
	}
	else if (a.size < b.size)
	{
		return false;
	}

	// case a.size == b.size
	for (int i = a.size - 1; i > 0; i--)
		if (a.arr[i] < b.arr[i])
			return false;

	return true;
}


/***********************************
	Addition of two Big Integers
***********************************/
bigInt bigIntAddition(bigInt a, bigInt b)
{
	bigInt result;
	
	bigIntTrim(a);
	bigIntTrim(b);

	if (!a.sign ^ b.sign)
	{
		result = operationAddition(a,b);
		result.sign = a.sign;
	}
	else
	{
		if (bigIntIsEqualBigger(a,b))
		{
			result = operationSubtraction(a,b);
			result.sign = a.sign;
		}
		else
		{
			result = operationSubtraction(b,a);
			result.sign = b.sign;
		}
	}
	
	return result;
}


/***********************************
	Addition of two positive Big Integers
***********************************/
bigInt operationAddition(bigInt a, bigInt b)
{
	if (a.size < b.size)
	{
		return operationAddition(b, a);
	}

	unsigned short 	size 	= a.size + 1;
	unsigned char* 	arr		= new unsigned char[size];
	std::fill_n(arr, size, 0); 

	int carry 	= 0;
	char tmp;

	for (int i = 0; i < b.size; i++)
	{
		tmp 	= a.arr[i] + b.arr[i] + carry;
		carry 	= tmp / 10;
		arr[i] 	= tmp % 10;
	}

	for (int i = b.size; i < a.size; i++)
	{
		tmp 	= a.arr[i] + carry;
		carry 	= tmp / 10;
		arr[i] 	= tmp % 10;
	}

	arr[size - 1] = carry;

	bigInt 			result 	= {.sign = true, .size = size, .arr = arr};
		
	bigIntTrim(result);
	return result;
}


/***********************************
	Subtraction of two positive Big Integers
	a > b
***********************************/
bigInt operationSubtraction(bigInt a, bigInt b)
{
	unsigned short 	size 	= a.size + 1;
	unsigned char* 	arr		= new unsigned char[size];
	std::fill_n(arr, size, 0); 

	int carry 	= 0;
	char tmp;

	for (int i = 0; i < b.size; i++)
	{
		tmp 	= a.arr[i] - b.arr[i] + carry;
		carry 	= tmp / 10;
		arr[i] 	= tmp % 10;
	}

	for (int i = b.size; i < a.size; i++)
	{
		tmp 	= a.arr[i] + carry;
		carry 	= tmp / 10;
		arr[i] 	= tmp % 10;
	}

	arr[size - 1] = carry;

	bigInt 			result 	= {.sign = true, .size = size, .arr = arr};
	bigIntTrim(result);
	return result;
}


/***********************************
	Compares a Fibonacci term number n
	n > 1
***********************************/
bigInt 		FibonacciSequence(unsigned int n)
{
	unsigned char first[] = {1};
	unsigned char second[] = {1};
	
	bigInt u0 = {.sign = true, .size = sizeof(first) / sizeof(first[0]), .arr = first};
	bigInt u1 = {.sign = true, .size = sizeof(second) / sizeof(second[0]), .arr = second};
	
	bigInt u2;

	for (int i = 0; i < n - 1; i++)
	{
		u2 = operationAddition(u1, u0);
		bigIntTrim(u2);

		u0 = u1;
		u1 = u2;
	}
	delete u0.arr;

	return u1;
}


/***********************************
	Multiplication of Big Integers
***********************************/
bigInt 		bigIntMultiply(bigInt a, bigInt b)
{
	int size = a.size + b.size;
	bigInt result = {.sign = !a.sign ^ b.sign,
					 .size = static_cast<unsigned short>(size),
					 .arr = new unsigned char[size]};
	std::fill_n(result.arr, result.size, 0);

	int carry 	= 0;
	int tmp		= 0;
	for (int i = 0; i < a.size; i++)
	{
		carry = 0;
		for (int j = 0; j < b.size; j++)
		{
			tmp 			= a.arr[i] * b.arr[j] + result.arr[i+j] + carry;
			carry			= tmp / 10;
			result.arr[i+j] = tmp % 10;
		}
		result.arr[i + b.size] = carry;
	}

	bigIntTrim(result);

	return result;
}


/***********************************
	Converter Int to Big Int
***********************************/
bigInt intToBigInt(uint64_t n)
{
	unsigned short 	size = 0;
	uint64_t	 	copy = n;
	
	while(copy)
	{
		copy /=10;
		size++;
	}

	bigInt result = {.sign = (n >= 0) ? true : false,
					.size = size,
					.arr = new unsigned char[size]};
	std::fill_n(result.arr, size, 0);

	for (int i = 0; i < size; i++)
	{
		result.arr[i] = n % 10;
		n /= 10;
	}

	return result;
}


/***********************************
	Factorial
***********************************/
bigInt 		bigIntFactorial(unsigned int n)
{
	bigInt result;

	bigInt tmpResult = intToBigInt(n);
	bigInt nInBigInt;

	for (int i = 1; i < n - 1; i++)
	{
		nInBigInt 	= intToBigInt(n - i);
		result 		= bigIntMultiply(tmpResult, nInBigInt);
		delete tmpResult.arr;
		delete nInBigInt.arr;
		tmpResult	= result;
	}
	
	return result;
}


/***********************************
	Converter Int to Big Int
	// no sign
***********************************/
uint64_t 	bigIntToInt(bigInt a)
{
	uint64_t result = 0;

	for (int i = a.size - 1; i >= 0; i--)
		result += static_cast<uint64_t>(pow(10, i)) * a.arr[i];
	
	return result;
}


/***********************************
	Division by 2
***********************************/
void 		bigIntRightShift(bigInt& e)
{
	bool check = false;
	for (int i = e.size - 1; i >= 0; i--)
	{
		if(!check && e.arr[i] == 1)
		{
			check = true;
			e.arr[i] = 0;
			continue;
		}

		int toDivide = check ? e.arr[i] + 10 : e.arr[i];

		e.arr[i] 	= toDivide / 2;
		check 		= toDivide % 2;
	}
	bigIntTrim(e);
}


/***********************************
	Big Int Mod
	// for positive only
	// !!!! is not working yet
***********************************/
bigInt 		bigIntMod(bigInt e, bigInt modulus)
{
	bigIntTrim(e);
	bigIntTrim(modulus);
	
	bigInt eCopy = {.sign = true,
					.size = e.size,
					.arr = new unsigned char[e.size]};
	for (int i = 0; i < e.size; i++)
	{
		eCopy.arr[i] = e.arr[i];
	}

	if (!bigIntIsEqualBigger(eCopy, modulus))
		return eCopy;

	bigIntTrim(eCopy);
	return eCopy;
}


/***********************************
	Power Modulo N [e inclusive]
***********************************/
bigInt 		bigIntExpmod(bigInt b, bigInt e, bigInt n)
{
	bigInt result = intToBigInt(1);
	bigInt tmpResult;
	while (e.size > 0)
	{
		if (e.arr[0] % 2 == 1) // To check
		{
			tmpResult = bigIntMultiply(result, b);
			delete result.arr;
		 	result = bigIntMod(tmpResult, n);
		 	delete tmpResult.arr;
		 }
		
		bigIntRightShift(e);
		
		tmpResult = bigIntMultiply(b, b);
		delete b.arr;
		b = bigIntMod(tmpResult, n);
		delete tmpResult.arr;
	}

	return result;
}