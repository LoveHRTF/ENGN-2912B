# HW6Part2 Ziwei Chen

## TA Comments:
* Use GNUPlot to plot the filter weights and the error signals.
* In your autocorrelation implementation your loop indices are offset by 1 (remember indexing starts from 0 in C++).
* Make sure you do not hardcode any numbers. Make use of the available class methods to determine the sizes of the signals.
* In LMSFilter, when estimating the value of mu, you crop rxx_ which becomes a signal of size L and try to access the (L+1)th element with rxx_(L_) which is out of bounds.
* Grade: [37/50]
* Late Penalty: None
* Total: [37/50]

## Important Notes:
* **Develop your code in the student branch and issue a pull request to the master branch before the assignment due date.**
* Modify the above name fields with your name and last name.
* **Use the CCV environment for development and testing. Note that this assignment SHOULD NOT be attempted on Windows or OSX.**
* Files with a DO NOT MODIFY comment need no modification or further implementation. Please do not modify them.
* **Make sure you push your latest changes before the deadline, i.e., do not forget to git push after every git commit.**
* Under the name field above, add your build status badge to this README file with the following syntax:
  - `![Build Status](https://travis-ci.com/ENGN2912B-2018/hw6part2-FrozenRouter.svg?token=Q7FZZqhVHSuDtZqw1zko&branch=master)`
  - The build status badge has two states: build passing and build failing. Build passing verifies that your code compiles/builds correctly and that the test cases pass successfully. Build failing, however, can be due to a failure in compilation or due to a successful compilation but failure(s) in test cases. Check the auto-grader build log on [travis-ci.com](https://travis-ci.com) by signing in with your GitHub account to get more details.
* If you have any questions, post them in #homework channel on Slack to start a discussion

# Goals:
## Problem 6.2:
* Read the problem description in the PDF file on Canvas.
* The observed noisy signal and the noise reference signals for this problem are available in binary format inside the `/data` folder. The MATLAB implementations of the adaptive noise cancellation systems using Wiener filter and the LMS filter are provided inside the `/srcMATLAB` folder. In MATLAB, run the main program `/srcMATLAB/anc_main.m`. You will first hear the observed noisy signal and then the noise cancelled output signal. Performance and spectrogram plots will also be output. What did you hear in the noise cancelled output signal?  
  - I heard `HOLLY LUYA!!!!!` !
* Study the implementations of the Wiener filter and the LMS filter algorithms. The derivation of the Wiener filter algorithm is provided in the PDF file. The LMS filter is an adaptive Wiener filter algorithm where Rxx and rdx are instantaneously estimated using the available data captured in sliding windows. You will implement the Wiener filter and the LMS filter algorithms in C++ using an abstract Filter base class and two derived classes with the help of the Armadillo scientific computing library! The CMake files provided will download and link the libraries to your project. To successfully do that, certain modules are needed to be loaded/unloaded on CCV. Load the following list of modules every time you log into a node on CCV or modify the contents of `.modules` file.
  - module unload intel/2017.0
  - module load lapack/3.7.0
  - module load openblas/0.2.19
  - module load atlas/3.10.3
  - module load gcc/7.2
  - module load cmake/3.8.0
* We are ready for the implementation. See the class declaration, member variables and methods of the abstract Filter class in `/src/anc.h`. Implement the constructors and the abstract member functions `execute` for the derived classes WienerFilter and LMSFilter in the header file. You need to also implement two helper methods `readBinaryFile` and `saveBinaryFile` for binary I/O processes. The corresponding cpp file `/src/anc.cpp` needs no implementation or modification. Please do not attempt to modify it.
* To build your project, as usual, create a build directory using `mkdir ./build`
* Use the following command to run cmake in build directory: `cmake -D CMAKE_CXX_COMPILER=g++ ..`
* Having successfully generated cmake files, run make in build directory: `make`
* Make sure that the code provided in `mainQ2.cpp` produces correct results
  - Run the executable in build directory: `./hw6Q2Executable`. Using the helper methods, the program will read the observed noisy signal and the noise reference signals stored in binary format from the `data` folder, create WienerFilter and LMSFilter objects, process the signals and will save the respective filter weights and the error signals inside the `results` folder.
* Use `gnuplot` library to plot the filter weight and error signal outputs of the WienerFilter and the LMSFilter objects. Commit and push the script used to generate the plots.
  - **Plots Should Be Here**
* Run GSuite tests in build directory: `./hw6Tests/02_ANCTests/02_runHW6ANCTests` and verify that your code passes the test cases.
  - The grading is not solely based on test success. The details of implementation and certain programming requirements of the problem that are not tested are also taken into consideration. Hence, a code that passes all the test cases may not earn you full marks and similarly a zero score is not given for a code that fails the test cases.

Good luck!

ENGN2912B TAs
