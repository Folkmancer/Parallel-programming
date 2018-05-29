#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int size, rank, i;
	double begin, end, time = 0.0, ftime = 0.0;
	/*������������� ����������  */
	MPI_Init(&argc, &argv);
	
	/*����������� ���������� ����� � ����������  */
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	/* ����������� ������������ ������ �� 0 �� (size-1) */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	begin = MPI_Wtime();
	/* ������ � ������� 0 �������� ������������ ������ ������,
	* � ������� ���������� ������������ MPI_COMM_WORLD,
	* �.�. ����� ��������� � ����������!!
	*/
	if (rank == 0) {
		printf("Total processes count = %d\n", size);
		printf("An elapsed wall clock time = %0.3g microseconds \n", ftime * 1000);
	}
	/*������ ������ ������� ������������ ���� ����� */
	printf("Hello! My rank in MPI_COMM_WORLD = %d\n", rank);
		/*��� ������ ��������� ����������*/
	end = MPI_Wtime();
	time += end - begin;
	MPI_Reduce(&time, &ftime, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Finalize();
	
	return 0;
}