#!/bin/bash

# To view submitted/running jobs: myq
# To kill a job: scancel <jobID>

# Running time: 2 minutes
#SBATCH --time=00:02:00

# Create 2*8 = 16 processes
#SBATCH --nodes=2
#SBATCH --tasks-per-node=8

# Specify job name
#SBATCH -J HelloWorldMPI

# Specify output file name
#SBATCH -o HelloWorldMPI-%j.out
#SBATCH -e HelloWorldMPI-%j.out

srun --mpi=pmi2 ./helloworld
