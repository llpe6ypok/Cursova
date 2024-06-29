#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cmath>

Matrix::Matrix(int n) {
    _matrixSize = n;
    _matrixValues.resize(n, std::vector<double>(n, 0));
}

Matrix::Matrix(const Matrix& other) {
    _matrixSize = other._matrixSize;
    _matrixValues = other._matrixValues;
}

void Matrix::matrixSetValue(const std::vector<std::vector<double>>& A) {
    for (int i = 0; i < _matrixSize; i++) {
        for (int j = 0; j < _matrixSize; j++) {
            _matrixValues[i][j] = A[i][j];
        }
    }
}


vector<double>& Matrix::operator[](int i) {
    return _matrixValues[i];
}

const vector<double>& Matrix::operator[](int i) const {
    return _matrixValues[i];
}

Matrix Matrix::multiplyMatrices(const Matrix& matrixA, Matrix& matrixB, int n) {
    Matrix result(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::substructMatrices(const Matrix& matrixA, const Matrix& matrixB, int n) {
    Matrix result(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return result;
}

vector<double> Matrix::matrixVectorMultiply(const Matrix& matrix, const vector<double>& vec, int n) {
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}
int Matrix::getMatrixSize()
{
    return _matrixSize;
}

void Matrix::setIdentity()
{
    for (int i = 0; i < _matrixSize; i++)
    {
        for (int j = 0; j < _matrixSize; j++)
        {
            _matrixValues[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}
