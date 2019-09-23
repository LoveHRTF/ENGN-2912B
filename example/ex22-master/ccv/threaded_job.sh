#!/bin/bash

# Request an hour of runtime:
#SBATCH --time=1:00:00

# Default resources are 1 core with 2.8GB of memory per core.

# Use more cores:
#SBATCH -c 16

# Specify a job name:
#SBATCH -J main4

# Specify an output file
#SBATCH -o MyThreadedJob-%j.out
#SBATCH -e MyThreadedJob-%j.out

# Run a command
./main4 7

