#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

#define CHUNKSIZE 3
#define N 100

int main()  
{
	double start_time = omp_get_wtime();
	int i, chunk;
	double a[N+1], b[N+1], c[N+1];
	chunk = CHUNKSIZE;

	for (i=0; i<N; i++) a[i] = b[i] = (double)i;

	#pragma omp parallel num_threads(4) shared(a,b,c,chunk) private(i)
	{
		#pragma omp for schedule(dynamic,chunk) nowait
			for (i=0; i<N; i++) {
				c[i] = a[i] + b[i];
				printf("I'm thread %d. Calculate %d iteration\n", omp_get_thread_num(), i);
			}
	}
	double time = omp_get_wtime() - start_time;
	std::cout << "Time: " << time << std::endl;
	system("pause");
	return 0;
}