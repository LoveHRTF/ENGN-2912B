# Extra Credit Assignment: VRML and Accelerated Computing
## Name: FirstName LastName

## Important Notes:
* Modify the above name fields with your first name and last name
* You are expected to create a *separate subdirectory* in your GitHub repository for each problem.  For example problem 7.1 would be in subdirectory `problem7.1`, 7.2 on subdirectory `problem7.2`, etc.
* Use CCV to implement your solution. The MeshLab program can be run on your local computer, but the program must compile and run on the CCV.  We are not using Travis CI for this assignment.
* **Note:** No template code or test cases are provided for problems 7.2-7.4 in this assignment. You must provide detailed build instructions (using CMake, make or SLURM batch script) for compiling and executing your code.  Include a .modules file in your repository with the necessary libraries to complile your code.
* 4 problem statements are given below. You will receive extra credit for every complete solution. Note that incomplete solutions will not be graded for partial credit.
* A short report should be included in your final submission (you can modify this README file, or place individual README.md files in each problem's subdirectory) describing your solution and results.  Include any necessary screen captures showing molecule visualization (for the VRML problem) or profiling performance (for the accelerated computing problems).

## Problem 1 (VRML Molecule Visualization):

Refer to the 7.1 assignment description located on Canvas.  The PDF describes the template code included in this repository and the specific directions for completing this problem.

# Accelerated Computing Problems:
For *each problem* described below, your solution must include the following:
* Solution obtained using *serial* (single thread, single process) computation.
* A *multi-threaded* implementation (using C++11 Threads)
* A *multi-threaded* implementation (using OpenMP). Evaluate the performance of your code by plotting runtime against number of threads. Comment on empirical gain in performance versus expected (theoretical) improvement.
* A *multi-process* implementation (using MPI). Profile your code and report performance metrics (runtime and memory footprint).
For profiling, you can use `time` utility, `std::chrono` library, or the `GProf` profiler.  Run the programs in a Monte Carlo analysis to improve the estimate for runtime.  10 iterations should be sufficient to reduce the runtime standard deviation, but include the mean and standard deviation in your reported results.

## Problem 2 (Estimation of PI):
The value of PI can be approximated by integrating 4/(1+x^2) from 0 to 1 using a Riemann sum. Write code to approximate PI using 100,000 uniformly sized partitions.

## Problem 3 (Image Denoising):
Use the Image class and the ImageDenoiser class from HW 4 (Problem 4.4) to remove noise in `noisyImage.pgm` using a median filter. Try different filter sizes. Comment on the trade-off between filter size, performance and image quality.

## Problem 4 (Heat Flow):
Solve the 1-D Laplace's equation to obtain steady state temperature on a rod of unit length with boundary conditions: T(x=0) = 273 K (0°C) and T(x=1) = 310 K (37°C). Compare the numerical solution to the analytical solution.
