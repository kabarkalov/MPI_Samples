#include <stdio.h>
#include <math.h>
#include <mpi.h>

double fi(double* x, int N)
{
	unsigned i = 0;
	double result = 0;
	for (i = 0; i < N; i++)result += x[i] * x[i];
	return result + 2;
}

int main(int argc, char* argv[])
{
	const int N = 2;
	const double h = 1e-5;

	int rank, numprocs, i, j, message;
	MPI_Status status;

	double lb[N], ub[N];

	// ������������� ���������� MPI
	if (MPI_Init(&argc, &argv) != MPI_SUCCESS)
	{
		printf("\n Failed to init MPI library");
		return -1;
	}
	// ��������� ���������� ��������� � ���������
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	numprocs = 2;
	// ��������� ����� ��������
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{
		//������������ ����� ������ � ������ ������� ���� ������������
		for (int i = 0; i < N; i++)
		{
			lb[i] = -1;
			ub[i] = 1;
		}
	}
	//�������� �������� �� ��� ��������
	MPI_Bcast(lb, N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(ub, N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	int size = (double)(ub[0] - lb[0]) / h;
	int size1 = (ub[0] - lb[0]) / numprocs / h;
	double l = rank * (ub[0] - lb[0]) / numprocs;
	//	double u=(rank+1)*(ub[0]-lb[0])/numprocs;
	double t_min[1] = { HUGE_VAL };
	double min[1];
	double value;
	double y[2];

	for (i = 0; i <= size1; i++)
	{
		for (j = 0; j <= size; j++)
		{
			y[0] = l + i * h;
			y[1] = lb[0] + j * h;
			value = fi(y,N);
			if (value < t_min[0])t_min[0] = value;
		}
	}
	//���� ���������� �� ���� ���������
	MPI_Reduce(t_min, min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
	//������ ���������� �� ������� ��������
	if (rank == 0) printf("\nMinimum = %10.5f\n", min[0]);
	// ���������� ���������� MPI
	if (MPI_Finalize() != MPI_SUCCESS)
	{
		printf("\n Failed to finalize MPI library");
		return -1;
	}

	return 0;
}
