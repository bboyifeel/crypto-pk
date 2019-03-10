#include <iostream>
#include <cmath>

void printEuclidsEquasion(int _r[3], int _q)
{
	std::cout << _r[0] << " = ";
	std::cout << _q << "*";
	std::cout << _r[1] << " + ";
	std::cout << _r[2];
}

int gcdEuclid(int _a, int _b)
{
	if (!_a || !_b)
		return _a^_b;

	int r[3] = { _a, _b, 0};
	int q = 0;

	do
	{
		q 		= r[0] / r[1];
		r[2] 	= r[0] - q * r[1];
		
		printEuclidsEquasion(r,q);
		std::cout << std::endl;

		r[0] = r[1];
		r[1] = r[2];
		r[2] = 0;
	
	} while(r[1] != 0);

	return std::abs(r[0]);
}

int main()
{
	int a = 12;
	int b = 15;
	
	int gcdAB = gcdEuclid(a,b);
	std::cout << "gcd(" <<a << "," << b << ") = " << gcdAB << std::endl;
	return 0;
}