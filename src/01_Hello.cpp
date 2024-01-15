#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	int rank, numprocs, i, message;
	// ������������� ���������� MPI
	MPI_Init(&argc, &argv);
	// ��������� ���������� ��������� � ���������
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	// ��������� ����� ��������
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("\n Hello from process %3d", rank);
	// ���������� ���������� MPI
	MPI_Finalize();
	return 0;
}
