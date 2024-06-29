#ifndef KRYLOVMETHODSOLVER_H
#define KRYLOVMETHODSOLVER_H

#include "Matrix.h"
#include "Solver.h"
using namespace std;
class KrylovMethodSolver : public Matrix, public Solver {
public:
    KrylovMethodSolver(const Matrix& matrix);
    Matrix getEigenVectors(const vector<double>& roots) override;
    void findp(const Matrix& matrix) override;

private:
    vector<vector<double>> yn;
};

#endif // KRYLOVMETHODSOLVER_H
