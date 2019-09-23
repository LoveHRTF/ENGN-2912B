#!/bin/bash

# Request an hour of runtime:
#SBATCH --time=1:00:00

# Default resources are 1 core with 2.8GB of memory per core.

# Use more cores:
#SBATCH -c 16

# Specify a job name:
#SBATCH -J main4

# Specify an array
#SBATCH --array=3-10

# Specify an output file
#SBATCH -e ArrayJob-%j.err
#SBATCH -o ArrayJob-%j.out

# Run a command
echo "Starting job $SLURM_ARRAY_TASK_ID on $HOSTNAME"
time ./main4 $SLURM_ARRAY_TASK_ID

