/*
* Пример 2
* Вывод разрешения таймера и определение времени на замер времени
*/

#include "mpi.h"
#include <stdio.h>

void main(int argc, char *argv[])
{
	int rank;
	double resol, begin, end;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	begin = MPI_Wtime();
	resol = MPI_Wtick();
	end = MPI_Wtime();
	printf("Process %d, resolution = %0.3g microseconds \n", rank, resol * 1000);
	printf("An elapsed wall clock time = %0.3g microseconds \n", (end - begin) * 1000);
	MPI_Finalize();
}