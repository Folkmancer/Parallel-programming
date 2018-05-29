#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

/**
 * Задача: перемножение матриц a и b
*/
#define SIZE (2000)

int main()
{
	double a[SIZE], b[SIZE], c[SIZE];
	int i,j,k;
	double start_time = omp_get_wtime();
	#pragma omp parallel shared(a, b, c) 
	{
		#pragma omp for private(k, j, i) schedule(dynamic)
		for (i = 0; i < SIZE; i++) {
			for (k = 0; k<SIZE; k++) {
				c[i, k] = 0;
				a[i, k] = rand() % 100;
				b[i, k] = rand() % 100;
			}
		}

		#pragma omp for private(k, j, i) schedule(dynamic)
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				for (k = 0; k < SIZE; k++) {
					c[i, k] = c[i, k] + a[i, j] * b[j, k];
				}
			}
		}
	}
	double time = omp_get_wtime() - start_time;
	printf("Total work time = %10.9f\n", time);
	system("pause");
	return 0;
}
