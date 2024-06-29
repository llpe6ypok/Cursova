#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;
class Matrix {
public:
    Matrix(int n = 0);
    Matrix(const Matrix& other);

    void matrixSetValue(const vector<vector<double>>& A);

    vector<double>& operator[](int i);
    const vector<double>& operator[](int i) const;

    Matrix multiplyMatrices(const Matrix& matrixA, Matrix& matrixB, int n);
    Matrix substructMatrices(const Matrix& matrixA, const Matrix& matrixB, int n);
    vector<double> matrixVectorMultiply(const Matrix& matrix, const vector<double>& vec, int n);
    int getMatrixSize();
    void setIdentity();

private:
    int _matrixSize;
    vector<vector<double>> _matrixValues;
};

#endif // MATRIX_H
