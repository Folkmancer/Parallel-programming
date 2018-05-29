#include <cstdlib>
#include <iostream>

int main()
{
	int i; 
	#pragma omp parallel for 
	for (i = 'a'; i <= 'z'; i++) std::cout << (char)i;// printf("%c", i);
	std::cout << std::endl;

	#pragma omp parallel private(i)
	for (i = 'a'; i <= 'z'; i++) std::cout << (char)i; //printf("%c", i);
	std::cout << std::endl;

	system("pause");
	return 0;
}