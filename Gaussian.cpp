#include "Gaussian.h"
#include "counter.h"
#include <vector>
#include <algorithm>

void Gaussian::forwardElimination(vector<vector<double>>& augmentedMatrix, int n) {
    for (int k = 0; k < n; k++) {
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            counter++;
            if (abs(augmentedMatrix[i][k]) > abs(augmentedMatrix[maxRow][k])) {
                maxRow = i;
            }
        }
        swap(augmentedMatrix[k], augmentedMatrix[maxRow]);
        for (int i = k + 1; i < n; i++) {
            double factor = augmentedMatrix[i][k] / augmentedMatrix[k][k];
            counter++;
            for (int j = k; j <= n; j++) {
                augmentedMatrix[i][j] -= factor * augmentedMatrix[k][j];
            }
        }
    }
}

vector<double> Gaussian::backSubstitution(const vector<vector<double>>& augmentedMatrix, int n) {
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = augmentedMatrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= augmentedMatrix[i][j] * solution[j];
        }
        counter++;
        solution[i] /= augmentedMatrix[i][i];
    }
    return solution;
}

vector<double> Gaussian::solveGaussian(const vector<vector<double>>& yn) {
    int n = yn.size() - 1;
    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            augmentedMatrix[i][j] = yn[j][i];
        }
        counter++;
    }

    forwardElimination(augmentedMatrix, n);
    return backSubstitution(augmentedMatrix, n);
}
