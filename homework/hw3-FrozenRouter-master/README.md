# HW3 Ziwei Chen
**TODO - Update your name in this readme.**

## TA Comments:

3.1) [20/20]

3.2) Use gprof to measure runtime performance. Large step size also affects the RK method. [18/20]

3.3) [20/20]

3.4) [20/20]

3.5) Create a helper method to compute string lengths. Improper handling of null termination character in erase.cpp function [10/20]

Total: 88/100

## Important Notes:
* Make sure you use the flag CMAKE_CXX_COMPILER=g++ when building on CCV
* The template code will not compile. This is intended behavior
* Make sure you push your last changes before the deadline
* If you had any questions, post them on Slack
* Use *git pull* to get the latest homework template
  - If you have already accepted the assignment and made changes to your local repository save the repository in a zip file
  - *git pull* may result in *merge* conflicts. If you are unsure how to resolve these, contact TAs on Slack

# Goals:

## Problem 3.1:
* Read the problem description in the PDF file on Canvas
* Implement the Matrix2x2 class in `/src/Matrix2x2.h` and `/src/Matrix2x2.cpp`
* Make sure that the code provided in `mainQ1.cpp` produces correct results
  - Create and run executable: `/build/hw3Q1Executable`
* Run GSuite tests: `/build/hw3Tests/01_ClassesTests/01_runHW3ClassesTests`

## Problem 3.2:
* Read the problem description in the PDF file on Canvas
* Implement the AbstractOdeSolver, the ForwardEulerSolver and the RungeKuttaSolver
  - Corresponding source and header files are already created in `/src/`. Some of these files need no modification which is explicitly stated.
  - **Note:** The user defined ODE is implemented directly in the `mainQ2.cpp` file. This user defined ODE function is passed to the solver class constructor by a pointer. Observe that your constructor for the ODE solvers accepts a pointer to a function with the appropriate type.
* Make sure that the code provided in `mainQ2.cpp` produces correct results
  - Create and run executable: `/build/hw3Q2Executable`
* Run GSuite tests: `/build/hw3Tests/02_ODETests/02_runHW3ODETests`
* Part 5: Describe the quantitative differences between the Forward Euler and Runge-Kutta methods:
  - Part a: The step size does not affect the Runge-Kutta solver, with a step size from 0.5 to 0.005, the result remains to be the same
  for test values in main.cpp, which was always 3.5. The Forward Euler solver, however, was highly affected by the step size. With setp of 0.5, the result was shown as 3.25, far away from 3.5. With step size of 0.00005, the value arrived 3.9997, which accuricy was improved, but was still not exact.
  - Part b: Runge-Kutta can return the exact 3.5 even with a step of 1, however the accuricy for Forward-Euler solver was highly impacted by the step size, and it would only be able to return the best approximated value. As a result, the Runge-Kutta solver is always more accurate than Forward-Euler solver, the extra amount of accuricy depends on the step size. Larger the step size, less accurate Runge-Kutta would be and more advantage Forward-Euler would have.
  - Part c: The Runge-Kutta method would be at least 5 times more computationally intensive than the Forward-Euler method with the certain given step size. It naturally adds more steps to calculate the k1 to k4 in every iteration. However, due to the accuracy, we may actually increase the step size when using Runge-Kutta method, which may be able to reduces the computational intensity.

## Problem 3.3:
* Read the problem description in the PDF file on Canvas
* Implement the translation function in `/src/translation.cpp`
* Answer the following question: "Why are some of the arguments declared as *const*?"
  - The arguments in this case were all passed by reference, which means the function was directly accessing to the memory location of these arguments. With that being said, any modification of these arguments in the function would result the arguments being modified even when the function was ended. To prevent this issue, therefore, we declar these arguments that need to be passed by reference, but should not be changed in function as *const*. *const* locks the value of these arguments, preventing the function from changing the value when accessing the addresses. 
* Write tests for your function in `mainQ3.cpp`
  - Create and run executable: `/build/hw3Q3Executable`
* Run GSuite tests: `/build/hw3Tests/03_TranslationTests/03_runHW3TranslationTests`

## Problem 3.4:
* Read the problem description in the PDF file on Canvas
* Implement the fibonacci function in `/src/fibonacci.cpp`. Make sure your implementation is recursive.
* Implement estimategoldenratio in `/src/estimategoldenratio.cpp` 
* Test your code in `mainQ4.cpp`:
  - Create and run executable: `/build/hw3Q4Executable`
* Run GSuite tests: `/build/hw3Tests/04_GoldenRatioTests/04_runHW3GoldenRatioTests`
* Document your findings here:
  - **TODO** Determine the limiting FN ratio that produces the golden ratio to a floating point precision of nine
  - Limiting FN Ratio: 1.618033989e+00

## Problem 3.5:
* Read the problem description in the PDF file on Canvas
* Write string processing functions in separate source and header files:
  - Put your declarations and implementation in `/src/concat.h`, `/src/concat.cpp`, `/src/substr.h`, `/src/substr.cpp`, `/src/erase.h`, `/src/erase.cpp`
  - Do **NOT** use the string class
  - If needed, use helper functions to keep your code short and to avoid redundancy
* Write tests for your code in `mainQ5.cpp`
* Run GSuite tests: `/build/hw3Tests/05_StringTests/05_runHW3StringTests`

Good luck!

ENGN2912B TAs
