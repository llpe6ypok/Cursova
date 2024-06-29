#include "Solver.h"
#include "Polynomial.h"
#include "counter.h"
#include <cmath>
#include <stdexcept>

vector<double> Solver::getEigenvalues(double tolerance, int maxIterations) {
    int n = p.size();
    vector<double> coefficients(n + 1, 1.0);
    for (int i = 1; i <= n; i++) {
        coefficients[i] = p[i - 1] * (-1.0);
    }

    return Polynomial::findAllRoots(coefficients, tolerance, maxIterations);
}

Matrix Solver::normalizeVectors(const Matrix& _matrixOfEigenVectors, int n) {
    Matrix normalizedVec(n);
    vector<double> length(n, 0.0);
    for (int i = 0; i < n; i++) {
        counter++;
        for (int j = 0; j < n; j++) {
            length[i] += _matrixOfEigenVectors[i][j] * _matrixOfEigenVectors[i][j];
        }
        length[i] = sqrt(length[i]);
    }
    for (int i = 0; i < n; i++) {
        counter++;
        for (int j = 0; j < n; j++) {
            normalizedVec[i][j] = _matrixOfEigenVectors[i][j] / length[i];
        }
    }
    return normalizedVec;
}

vector<double> Solver::getP() {
    return p;
}
