#include <omp.h>
#include <stdio.h>
#include <time.h>

#define N 10000

int main ()
{
	int i;
	double a[N+1], b[N+1], c[N+1], d[N+1];
	
	/* Some initializations */
	for (i=0; i < N; i++)
		a[i] = i * 1.5;
		b[i] = i + 22.35;
	double start_time = omp_get_wtime();
	#pragma omp parallel num_threads(2) shared(a,b,c,d) private(i)
	{
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				for (i=0; i < N; i++)
					c[i] = a[i] + b[i];
				printf("I'm thread %d. Calculate vectors sum.\n", omp_get_thread_num());
			}
			#pragma omp section
			{
				for (i=0; i < N; i++)
					d[i] = a[i] * b[i];
				printf("I'm thread %d. Calculate vectors product.\n", omp_get_thread_num());
			}
		}  /* end of sections */
	}  /* end of parallel section */
	double time = omp_get_wtime() - start_time;
	printf("The time of section was %f seconds\n", time);
	system("pause");
	return 0;
}


