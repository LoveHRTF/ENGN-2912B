#include <iostream>
#include <vector>
#include "mpi.h"

using namespace std;

// module load mpi/openmpi_2.0.3_gcc
// compile with: mpicxx ./dotproduct2.cpp -o dotproduct2
// Run multiple processes on local machine (single node): mpiexec -n 11 ./dotproduct2

double serve_data(int N, int num_procs, int chunk_size){

  // initialize vectors
  vector<double> x;
  vector<double> y;
  for (int i = 0; i < N; i++){
    x.push_back((double) (i+1));
    y.push_back(1.0/(i+1));
  }

  // divide data into chunks and send to workers
  for(int i = 1; i < num_procs; i++){
    int cnt = 0;
    double data[2*chunk_size];
    for (int j = 0; j < chunk_size; j++){
      data[cnt] = x.back();
      data[cnt+1] = y.back();
      x.pop_back();
      y.pop_back();
      cnt += 2;
    }
    MPI_Send(&data[0], 2*chunk_size, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
  }

  // collect results
  MPI_Status status;
  double dotprod;
  for(int i = 1; i < num_procs; i++){
    double res;
    MPI_Recv(&res, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &status);
    dotprod += res;
  }

  return(dotprod);

}

void compute_dotproduct(int rank, int chunk_size){

  MPI_Status status;
  double data_recvd[2*chunk_size];
  MPI_Recv(&data_recvd[0], 2*chunk_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);

  int j = 0;
  double localdotprod = 0.0;
  while (j < 2*chunk_size){
      localdotprod += data_recvd[j] * data_recvd[j+1];
      j += 2;
  }

  cout << "Rank: " << rank << " Local Dot Product: " << localdotprod << endl;

  MPI_Send(&localdotprod, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

}

int main(int argc, char* argv[]) {

  const int N = 2000;
  int rank, num_procs;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  int chunk_size = N/(num_procs-1);
  double result;

  if (rank == 0){

    // master process
    result = serve_data(N, num_procs, chunk_size);
    cout << "Dot Product: " << result << endl;

  } else {

    // worker processes
    compute_dotproduct(rank, chunk_size);

  }

  MPI_Finalize();

  return 0;

}
