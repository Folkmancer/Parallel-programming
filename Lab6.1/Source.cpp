#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int size, rank, i;
	double begin, end, time = 0.0, ftime = 0.0;
	/*инициализация библиотеки  */
	MPI_Init(&argc, &argv);
	
	/*определение количества задач в приложении  */
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	/* определение собственного номера от 0 до (size-1) */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	begin = MPI_Wtime();
	/* задача с номером 0 сообщает пользователю размер группы,
	* к которой прикреплен коммуникатор MPI_COMM_WORLD,
	* т.е. число процессов в приложении!!
	*/
	if (rank == 0) {
		printf("Total processes count = %d\n", size);
		printf("An elapsed wall clock time = %0.3g microseconds \n", ftime * 1000);
	}
	/*каждая задача выводит пользователю свой номер */
	printf("Hello! My rank in MPI_COMM_WORLD = %d\n", rank);
		/*Все задачи завершают выполнение*/
	end = MPI_Wtime();
	time += end - begin;
	MPI_Reduce(&time, &ftime, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Finalize();
	
	return 0;
}