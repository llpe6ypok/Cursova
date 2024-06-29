#ifndef GAUSSIAN_H
#define GAUSSIAN_H

#include <vector>
using namespace std;
class Gaussian {
public:
    static void forwardElimination(vector<vector<double>>& augmentedMatrix, int n);
    static vector<double> backSubstitution(const vector<vector<double>>& augmentedMatrix, int n);
    static vector<double> solveGaussian(const vector<vector<double>>& yn);
};

#endif // GAUSSIAN_H
