#include "LevereMethodSolver.h"
#include "Gaussian.h"
#include "counter.h"

LevereMethodSolver::LevereMethodSolver(const Matrix& matrix) {
    findp(matrix);
}

Matrix LevereMethodSolver::getEigenVectors(const vector<double>& roots) {
    int n = _matrixOfVectors.getMatrixSize();
    Matrix _matrixOfEigenVectors(n);
    for (int i = 0; i < n; i++) {
        vector<double> y(n, 0);
        y = _matrixOfVectors[n - 1];
        for (int j = 0; j < n - 1; j++) {
            counter++;
            for (int k = 0; k < n; k++)
            {
                y[k] = roots[i] * y[k] + _matrixOfVectors[j][k];
            }
        }
        _matrixOfEigenVectors[i] = y;
    }
    return normalizeVectors(_matrixOfEigenVectors, n);
}

void LevereMethodSolver::findp(const Matrix& matrix) {
    Matrix An = matrix;
    int n = An.getMatrixSize();
    Matrix B(n);
    Matrix E(n);
    E.setIdentity();
    p.resize(n);
    _matrixOfVectors = E;
    for (int i = 0; i < n; i++) {
        Matrix En = E;
        double sum = 0.0;
        counter++;
        for (int j = 0; j < n; j++) {
            sum += An[j][j];
        }
        counter++;
        p[i] = (1.0 / (i + 1)) * sum;
        counter++;
        for (int j = 0; j < n; j++)
        {
            En[j][j] *= p[i];
        }
        counter++;
        B = substructMatrices(An, En, n);
        for (int j = 0; j < n; j++) {
            _matrixOfVectors[i][j] = B[j][0];
        }
        counter++;
        An = multiplyMatrices(matrix, B, n);
    }
    for (int i = 0; i < n; i++) {
        _matrixOfVectors[n - 1][i] = 0.;
    }
    _matrixOfVectors[n - 1][0] = 1.;
}
