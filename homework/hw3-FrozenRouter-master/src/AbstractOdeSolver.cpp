// Abstract ODE solver methods

#include "AbstractOdeSolver.h"

// TODO: Implement the following methods:
// 1) AbstractOdeSolver::SetStepSize
// 2) AbstractOdeSolver::SetTimeInterval
// 2) AbstractOdeSolver::SetInitialValue

void AbstractOdeSolver::SetStepSize(double h){
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1){
    finalTime = t1;
    initialTime = t0;
}

void AbstractOdeSolver::SetInitialValue(double y0){
    initialValue = y0;
}
