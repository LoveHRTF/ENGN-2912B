#include <iostream>
#include "mpi.h"

using namespace std;

// module load mpi/openmpi_2.0.3_gcc
// compile with: mpicxx ./helloworld.cpp -o helloworld
// Run on multiple compute nodes on CCV: srun -N2 -n16 --mpi=pmi2 ./helloworld
// Submit a batch job on CCV using shell script: sbatch ./mpiBatch.sh
// Run multiple processes on local machine (single node): mpiexec -n 16 ./helloworld

int main(int argc, char* argv[]) {

  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  char myName[MPI_MAX_PROCESSOR_NAME];
  int resultLength;
  MPI_Get_processor_name(myName, &resultLength);

  cout << "Hello World! Process: " << rank << " out of " << size << " running on: " << myName << endl;

  MPI_Finalize();

  return 0;

}
