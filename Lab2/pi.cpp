#include <stdio.h>
#include <time.h>
#include <iostream>
#include <omp.h>

long long num_steps = 1000000000;
double step;

int main(int argc, char* argv[])
{
		double x, pi, sum = 0.0;
		int i;
		step = 1. / (double)num_steps;
		double start_time = omp_get_wtime();
		#pragma omp parallel private(x, i) shared(step)
		{
				#pragma omp for reduction (+:sum)
				for (i = 0; i < num_steps; i++)
				{
					x = (i + .5)*step;
					sum = sum + 4.0 / (1. + x * x);
				}
		}
		pi = sum * step;
		double time = omp_get_wtime() - start_time;
		printf("The value of PI is %15.12f\n", pi);
		printf("The time to calculate PI was %f seconds\n", time);
		system("pause");
	return 0;
}