#include <vector>
#include <iostream>

template<class T>
void 	printVector(std::vector<T> vec)
{
	std::cout << "[ "; 
	for(auto item: vec)
	{
		std::cout << item << " ";
	}
	std::cout << "]";
	std::cout << std::endl;
}