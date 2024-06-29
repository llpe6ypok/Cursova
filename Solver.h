#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "Matrix.h"
using namespace std;
class Solver {
public:
    virtual Matrix getEigenVectors(const vector<double>& roots) = 0;
    virtual void findp(const Matrix& matrix) = 0;
    vector<double> getEigenvalues(double tolerance = 1e-7, int maxIterations = 1000);
    Matrix normalizeVectors(const Matrix& _matrixOfEigenVectors, int n);
    vector<double> getP();

protected:
    vector<double> p;
    Matrix _matrixOfVectors;
};

#endif
