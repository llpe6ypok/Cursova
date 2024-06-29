#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
using namespace std;
class Polynomial {
public:
    static double evaluate(const vector<double>& coefficients, double x);
    static double derivative(const vector<double>& coefficients, double x);
    static double findRootNewtonRaphson(const vector<double>& coefficients, double tolerance = 1e-7, int maxIterations = 1000);
    static vector<double> deflate(const vector<double>& coefficients, double root);
    static vector<double> findAllRoots(const vector<double>& coefficients, double tolerance = 1e-7, int maxIterations = 1000);
};

#endif // POLYNOMIAL_H
