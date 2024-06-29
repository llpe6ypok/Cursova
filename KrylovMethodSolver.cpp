#include "KrylovMethodSolver.h"
#include "Gaussian.h"
#include "counter.h"

KrylovMethodSolver::KrylovMethodSolver(const Matrix& matrix) {
    findp(matrix);
}

Matrix KrylovMethodSolver::getEigenVectors(const vector<double>& roots) {
    int n = p.size();
    Matrix _matrixOfEigenVectors(n);
    Matrix q(n);
    for (int i = 0; i < n; i++) {
        q[i][0] = 1.0;
    }
    vector<double> coefficients(n + 1, 1.0);

    for (int i = 0; i < n; i++) {
        coefficients[i] = p[i];
    }
    counter++;

    for (int i = 0; i < n; i++) {
        counter++;
        for (int j = 1; j < n; j++) {
            q[i][j] = roots[i] * q[i][j - 1] - coefficients[j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += q[i][k] * yn[k][j];
            }
            counter++;
            _matrixOfEigenVectors[i][j] = sum;
        }
    }
    return normalizeVectors(_matrixOfEigenVectors, n);
}

void KrylovMethodSolver::findp(const Matrix& matrix) {
    Matrix matrixA = matrix;
    int n = matrixA.getMatrixSize();
    p.resize(n);
    yn.resize(n + 1, vector<double>(n, 0));

    yn[0][0] = 1.;

    for (int i = 0; i < n; i++) {
        yn[i + 1] = matrixVectorMultiply(matrixA, yn[i], n);
        counter++;
    }

    for (int i = 0; i < n / 2; i++) {
        swap(yn[n - i - 1], yn[i]);
    }
    p = Gaussian::solveGaussian(yn);
}
