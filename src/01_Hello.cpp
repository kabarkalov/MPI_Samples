#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	int rank, numprocs, i, message;
	// инициализация библиотеки MPI
	MPI_Init(&argc, &argv);
	// получение количества процессов в программе
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	// получение ранга процесса
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("\n Hello from process %3d", rank);
	// завершение библиотеки MPI
	MPI_Finalize();
	return 0;
}
