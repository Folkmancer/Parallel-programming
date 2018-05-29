#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

/**
 * Задача: умножение вектора a на вектор b
*/
#define N 100000

int main()
{
	int i, j, sum = 0, a[N], b[N];

	for (i = 0; i < N; i++) {
		a[i] = N - i - 1;
		b[i] = i;
		printf("\na[] = ");
		for (i = 0; i < N; i++)
			printf("%d ", a[i]);
		printf("\nb[] = ");
	}

	for (i = 0; i < N; i++)
		printf("%d ", b[i]);
	double start_time = omp_get_wtime();
#pragma omp parallel private(i) shared(a,b) 
		{
			#pragma omp for reduction(+:sum) schedule(static)
			for (i = 0; i < N; i++)
				sum = sum + a[i] * b[i];
		}
	double time = omp_get_wtime() - start_time;
	printf("\nMultiplication is = %d\n", sum);
    printf ("Total work time = %10.9f\n", time);
	system("pause");
	return 0;
}
