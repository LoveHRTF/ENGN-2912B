# HW6Part1 Ziwei Chen

## TA Comments:
* All type 2 errors should be thrown in a do-while loop. (-2 pts) 
* Within a given line in a data file, one or more regex matches may exist. You skip to the next line after finding one match. (-3 pts) 
* Operator overloading for & operator should return the kth element of private member variable searchResults_ by reference. (-1 pt)
* Grade: [44/50]
* Late Penalty: None
* Total: [44/50]

## Important Notes:
* **Develop your code in the student branch and issue a pull request to the master branch before the assignment due date.**
* Modify the above name fields with your name and last name.
* **Use the CCV environment for development and testing. Note that this assignment SHOULD NOT be attempted on Windows or OSX.**
* Files with a DO NOT MODIFY comment need no modification or further implementation. Please do not modify them.
* **Make sure you push your latest changes before the deadline, i.e., do not forget to git push after every git commit.**
* Under the name field above, add your build status badge to this README file with the following syntax:
  - `![Build Status](https://travis-ci.com/ENGN2912B-2018/hw6part1-FrozenRouter.svg?token=Q7FZZqhVHSuDtZqw1zko&branch=master)`
  - The build status badge has two states: build passing and build failing. Build passing verifies that your code compiles/builds correctly and that the test cases pass successfully. Build failing, however, can be due to a failure in compilation or due to a successful compilation but failure(s) in test cases. Check the auto-grader build log on [travis-ci.com](https://travis-ci.com) by signing in with your GitHub account to get more details.
* If you have any questions, post them in #homework channel on Slack to start a discussion

# Goals:
## Problem 6.1:
* Read the problem description in the PDF file on Canvas.
* See the class declaration, member variables and methods of the dnaFindPattern class in `/src/dnaFindPattern.h`. Implement the methods of the class in the header file. The corresponding cpp file `/src/dnaFindPattern.cpp` needs no implementation or modification. Please do not attempt to modify it.
* Certain modules are needed to be loaded for this problem. Load the following list of modules every time you log into a node on CCV or modify the contents of `.modules` file.
  - module load gcc/7.2
  - module load boost/1.63.0
  - module load cmake/3.8.0
* As a preprocessing step, we need to download some DNA sequences from Kaggle. Run the script `downloadData.sh` in the homework root directory which will download and unzip certain DNA sequences for tests. The datasets only need to be downloaded once.
* We are ready to build the project. As usual, create a build directory using `mkdir ./build`
* Use the following command to run cmake in build directory: `cmake -D CMAKE_CXX_COMPILER=g++ ..`
* Having successfully generated cmake files, run make in build directory: `make`
* Make sure that the code provided in `mainQ1.cpp` produces correct results
  - Run the executable in build directory: `./hw6Q1Executable` with command line arguments, i.e., argv[1]: path to a directory or file, argv[2]: regex string
* Run GSuite tests in build directory: `./hw6Tests/01_DNAPatternTests/01_runHW6DNAPatternTests` and verify that your code passes the test cases.
  - The grading is not solely based on test success. The details of implementation and certain programming requirements of the problem that are not tested are also taken into consideration. Hence, a code that passes all the test cases may not earn you full marks and similarly a zero score is not given for a code that fails the test cases.

Good luck!

ENGN2912B TAs
