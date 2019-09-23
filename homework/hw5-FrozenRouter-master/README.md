# HW5 Ziwei Chen

## TA Comments:

5.1) Please format your code such that each line has a single statement. 4x4 double test failed. Use helper method for allocation. Your matrix multiplication method is incorrect. The determinant and the inverse methods are incomplete. [36/40]

5.2) [30/30]

5.3) Make sure the size of the output signal is correct. (input.size()+filter.size()-1) [29/30]

Total: 95/100

## Important Notes:
* Check out your repository on the **student** branch:  `git clone -b student <repo-name>`
* Modify the above name fields with your name and surname
* **Use the CCV environment for development and testing**
* Files with a DO NOT MODIFY comment need no modification or further implementation. Please do not modify them
* The homework template will compile but the executables will not produce meaningful results
* Make sure you push your latest changes before the deadline
* Check the auto-grader build success on <https://travis-ci.com/> by signing in with your GitHub account
* OPTIONAL : Under the name field above, add your build status badge to this README file with the following syntax
  - `![Build Status](https://travis-ci.com/ENGN2912B-2018/hw5-<YOUR GITHUB ACCOUNT NAME HERE>.svg?token=Q7FZZqhVHSuDtZqw1zko&branch=master)`
* If you have any questions, post them in #homework channel on Slack to start a discussion

# Goals:
## Problem 5.1:
* Read the problem description in the PDF file on Canvas
* See the class definition, member variables and methods, of the templated Matrix class in `/src/Matrix.h`. Implement the methods of the templated class in the header file. Read and understand the proper ways of separating the definition and the declaration of templated classes on the following website
  - <https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl>
* Make sure that the code provided in `mainQ1.cpp` produces correct results
  - Compile and run the main executable: `/build/hw5Q1Executable`
* Run GSuite tests: `/build/hw5Tests/01_TemplatedMatrixTests/01_runHW5TemplatedMatrixTests`

## Problem 5.2:
* Read the problem description in the PDF file on Canvas
* See the function prototypes in `/src/RNG.h`. Implement the functions in `/src/RNG.cpp`
* Make sure that the code provided in `mainQ2.cpp` produces correct results
  - Compile and run the main executable: `/build/hw5Q2Executable`
* Run GSuite tests: `/build/hw5Tests/02_RNGTests/02_runHW5RNGTests`

## Problem 5.3:
* Read the problem description in the PDF file on Canvas
* See the class declaration in `/src/firFilter.h`. Implement the methods of the class in `/src/firFilter.cpp`
* Make sure that the code provided in `mainQ3.cpp` produces correct results
  - Compile and run the main executable: `/build/hw5Q3Executable`
* Run GSuite tests: `/build/hw5Tests/03_FIRTests/03_runHW5FIRTests`

Good luck!

ENGN2912B TAs
