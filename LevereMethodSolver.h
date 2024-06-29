#ifndef LEVEREMETHODSOLVER_H
#define LEVEREMETHODSOLVER_H

#include "Matrix.h"
#include "Solver.h"
using namespace std;
class LevereMethodSolver : public Matrix, public Solver {
public:
    LevereMethodSolver(const Matrix& matrix);
    Matrix getEigenVectors(const vector<double>& roots) override;
    void findp(const Matrix& matrix) override;
};

#endif // LEVEREMETHODSOLVER_H
