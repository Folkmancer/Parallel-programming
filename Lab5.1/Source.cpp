/*
* ������ 1
* ����������� ���������� ��������� � ���������� � ����������� ������ �������� � ������
*/

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int size, rank, i;
	/*������������� ����������  */
	MPI_Init(&argc, &argv);
	/*����������� ���������� ����� � ����������  */
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	/* ����������� ������������ ������ �� 0 �� (size-1) */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	/* ������ � ������� 0 �������� ������������ ������ ������,
	* � ������� ���������� ������������ MPI_COMM_WORLD,
	* �.�. ����� ��������� � ����������!!
	*/
	printf("Hello, world! I am %d process from %d processes!", rank, size);
	/*��� ������ ��������� ����������*/
	MPI_Finalize();
	return 0;
}