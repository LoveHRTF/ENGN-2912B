#include <iostream>
#include <vector>
#include <unistd.h>
#include "mpi.h"

using namespace std;

// module load mpi/openmpi_2.0.3_gcc
// compile with: mpicxx ./sendreceive.cpp -o sendreceive
// Run multiple processes on local machine (single node): mpiexec -n 4 ./sendreceive

int main(int argc, char* argv[]) {

  int rank;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {

    vector<double> p0_list;
    p0_list.push_back(1.0);
    p0_list.push_back(1.5);
    p0_list.push_back(2.0);
    p0_list.push_back(5.5);
    p0_list.push_back(11.2);

    /*
    * int MPI_Send (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
    * buf = reference to data to be sent
    * count = number of items in the message
    * datatype = implies size of items in the message
    * dest = rank of process to receive the message
    * tag = programmer specified identifier (used to organize messages)
    */
    MPI_Send(&p0_list[0], 5, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);

    cout << "Message sent by process " << rank << endl;

    p0_list.resize(5);
    MPI_Recv(&p0_list[0], 5, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);

    cout << "Process " << rank << " received: ";
    for(int i = 0; i < p0_list.size(); ++i){
      cout << p0_list[i] << " ";
    }
    cout << endl;

  } else {

    if (rank == 1){

      vector<double> p1_list;
      p1_list.resize(5);

      /*
      * int MPI_Recv (void *buf, int count, MPI_Datatype datatype, int source, int tag,
      * MPI_Comm comm, MPI_Status *status)
      * buf = reference to data to be sent
      * count = number of items in the message
      * datatype = implies size of items in the message
      * source = rank of process from which to receive the message
      * tag = programmer specified identifier (used to organize messages)
      * status = pointer to structure storing misc. information about the message:
      *   status.MPI_SOURCE (rank of sender)
      *   status.MPI_TAG (tag of message)
      *   status.MPI_ERROR (error code)
      */
      MPI_Recv(&p1_list[0], 5, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);

      cout << "Process " << rank << " received: ";
      for(int i = 0; i < p1_list.size(); ++i){
        cout << p1_list[i] << " ";
        p1_list[i] = p1_list[i] * 2.0;
      }
      cout << endl;

      MPI_Send(&p1_list[0], 5, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

      cout << "Message sent by process " << rank << endl;

    } else {

      int sleeptime = 2;
      sleep(sleeptime);
      cout << "Process " << rank << " slept for " << sleeptime << " secs and exited." << endl;

    }

  }

  MPI_Finalize();

  return 0;

}
