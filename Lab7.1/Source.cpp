/*
 * Пример 1
 * Рассылка строк массива с использованием функции MPI_Scatter
 */

#include <mpi.h>
#include <stdio.h>
#include <cstdlib>
#define N 4

int main(int argc, char **argv)
{
	int size, rank, sendcount = N, recvcount = N, source = 1, root = 0;
	float recvbufScatter[N], *recvbufGather;

	float sendbuf[N][N] = {
		{ 1.0, 2.0, 3.0, 4.0 },
		{ 5.0, 6.0, 7.0, 8.0 },
		{ 9.0, 10.0, 11.0, 12.0 },
		{ 13.0, 14.0, 15.0, 16.0 }
	};

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size == N) {
		/*MPI_Scatter(sendbuf, sendcount, MPI_FLOAT, recvbufScatter, recvcount,
			MPI_FLOAT, source, MPI_COMM_WORLD);

		printf("rank= %d  Results: %f %f %f %f\n", 
			rank, 
			recvbufScatter[0],
			recvbufScatter[1],
			recvbufScatter[2], 
			recvbufScatter[3]
		);*/

		recvbufGather = (float *)malloc(size * N * sizeof(float));
		MPI_Gather(sendbuf[rank], N, MPI_FLOAT, recvbufGather, recvcount, MPI_FLOAT, root, MPI_COMM_WORLD);
		if (rank == root) {
			for (int i = 0; i < size * N; i++) {
				printf("rank= %d line = %d Results: %f\n", rank, i, recvbufGather[i]);
			}
		}
	}
	else
		printf("Must specify %d processors. Terminating.\n", N);
	MPI_Finalize();
}