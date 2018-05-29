#include "omp.h"
#include <iostream>
#include <string>

int main(void)
{
	omp_set_num_threads(8);
	#pragma omp parallel
	{
		int nTread = omp_get_thread_num();
		int nThreads = omp_get_num_threads();
		std::cout << ("Hello, world! I am " + std::to_string(nTread) + " thread from " + std::to_string(nThreads) + " threads!\n");
	}
	system("pause");
	return 0;
}