#include <iostream>
#include "mpi.h"

using namespace std;

// module load mpi/openmpi_2.0.3_gcc
// compile with: mpicxx ./dotproduct.cpp -o dotproduct
// Run multiple processes on local machine (single node): mpiexec -n 10 ./dotproduct

const int N = 2000;
double x[N];
double y[N];

double dotProduct(double *xdata, double *ydata, int start, int end) {
  int index;
  double prod = 0.0;
  for (index = start; index < end; index++) {
    prod += xdata[index] * ydata[index];
  }
  return prod;
}

int main(int argc, char* argv[]) {

  int i;
  double result;

  int rank, num_procs;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  // initialize global array values
  for (i = 0; i < N; i++){
    x[i] = (double) (i+1);
    y[i] = 1.0/(i+1);
  }

  MPI_Barrier(MPI_COMM_WORLD);

  // assuming N is totally divisible by num_procs
  int local_N = N / num_procs;

  double local_prod;
  local_prod = dotProduct(x, y, rank * local_N, (rank + 1) * local_N);

  cout << "Process " << rank << " Local Product: " << local_prod << endl;

  MPI_Reduce(&local_prod, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    cout << "Dot Product Result: " << result << endl;
  }

  MPI_Finalize();

  return 0;

}
