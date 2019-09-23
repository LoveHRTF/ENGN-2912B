#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "gtest/gtest.h"
#include "AbstractOdeSolver.h"
#include "ForwardEulerSolver.h"
#include "RungeKuttaSolver.h"

using namespace std;

int FEPoints_ODE = 0;
int RKPoints_ODE = 0;
int maxPoints = 5;

double RHS(double y, double t){
  double dydt = -(2*y)/t + t - 1 + 1/t;
  return dydt;
}

TEST(hw3ODETests, ForwardEulerTest){

  double t0 = 1.0;
  double y0 = 0.5;
  double t1 = 2.0;
  double step = 0.05;
  double analytic_sol = (3*pow(t1, 4) - 4*pow(t1,3) + 6*pow(t1,2) + 1) / (12*pow(t1,2));

  bool testFlag;

  // TEST CASE 0
  testFlag = true;
  ForwardEulerSolver* p_ode1 = new ForwardEulerSolver(RHS);
  p_ode1->SetStepSize(step);
  p_ode1->SetTimeInterval(t0, t1);
  p_ode1->SetInitialValue(y0);
  double res1 = p_ode1->SolveEquation();

  cout << "Forward Euler Solver solution = " << res1 << endl;

  EXPECT_NEAR(analytic_sol, res1, 1e-2);
  if(HasFailure())
  {
      cerr << "\nForward Euler Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag){
      FEPoints_ODE += 5;
  }

  delete p_ode1;

  cout << "\nScore ForwardEuler Test: " << FEPoints_ODE << "/" << maxPoints << endl;

}


TEST(hw3ODETests, RungeKuttaTest){

  double t0 = 1.0;
  double y0 = 0.5;
  double t1 = 2.0;
  double step = 0.05;
  double analytic_sol = (3*pow(t1, 4) - 4*pow(t1,3) + 6*pow(t1,2) + 1) / (12*pow(t1,2));

  bool testFlag;

  // TEST CASE 1
  testFlag = true;

  RungeKuttaSolver* p_ode2 = new RungeKuttaSolver(RHS);
	p_ode2->SetStepSize(step);
	p_ode2->SetTimeInterval(t0, t1);
	p_ode2->SetInitialValue(y0);
	double res2 = p_ode2->SolveEquation();

	cout << "Runge-Kutta Solver solution = " << res2 << endl;
  cout << "Runge-Kutta Solver solution diff = " << abs(res2 - analytic_sol) << endl;

  EXPECT_NEAR(analytic_sol, res2, 1e-7);
  if(HasFailure())
  {
      cerr << "\nRunge-Kutta Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag){
      RKPoints_ODE += 5;
  }

  delete p_ode2;

  cout << "\nScore RungeKutta Test: " << RKPoints_ODE << "/" << maxPoints << endl;

}
