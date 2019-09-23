#include <iostream>
#include "ForwardEulerSolver.h"
#include "RungeKuttaSolver.h"

using namespace std;

// Question 3.2: ODE Solvers
// TODO: Implement the AbstractOdeSolver, the ForwardEulerSolver and the RungeKuttaSolver
// in src/AbstractOdeSolver.cpp, src/ForwardEulerSolver.cpp, and src/RungeKuttaSolver.cpp

double RHS(double y, double t) {
	double dydt = 1 + t;
	return dydt;
}

int main() {

	double t0 = 0.0; // start time
	double t1 = 1.0; // end time
	double y0 = 2; // initial value
	double step = 0.05; // step size
	double res1, res2, ana; // holder for resultant values

	ForwardEulerSolver* p_ode1 = new ForwardEulerSolver(RHS);
	p_ode1->SetStepSize(step);
	p_ode1->SetTimeInterval(t0, t1);
	p_ode1->SetInitialValue(y0);
	res1 = p_ode1->SolveEquation();
	cout << "Forward Euler Solver solution = " << res1 << endl;

	RungeKuttaSolver* p_ode2 = new RungeKuttaSolver(RHS);
	p_ode2->SetStepSize(step);
	p_ode2->SetTimeInterval(t0, t1);
	p_ode2->SetInitialValue(y0);
	res2 = p_ode2->SolveEquation();
	cout << "Runge-Kutta Solver solution = " << res2 << endl;

	// ground truth
	ana = (t1*t1 + 2 * t1 + 4) / 2;
	cout << "Analytic solution = " << ana << endl;

	// cleanup
	delete p_ode1;
	delete p_ode2;

	return 0;

}
