#include <omp.h>
#include <iostream>

int main()
{
	int rank;
	#pragma omp parallel private(rank) num_threads(3)
	{
		rank = omp_get_thread_num();
		printf("My rank = %d\n", rank);
		if(rank == 0) printf("This message is only for private variables!\n");
	}
	system("pause");
	return 0;
}