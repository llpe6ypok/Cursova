#include "Polynomial.h"
#include "counter.h"
#include <cmath>
#include <stdexcept>

double Polynomial::evaluate(const vector<double>& coefficients, double x) {
    double value = 0;
    for (int i = 0; i < coefficients.size(); i++) {
        value += coefficients[i] * pow(x, coefficients.size() - 1 - i);
    }
    return value;
}

double Polynomial::derivative(const vector<double>& coefficients, double x) {
    double value = 0;
    for (int i = 0; i < coefficients.size() - 1; i++) {
        value += coefficients[i] * (coefficients.size() - 1 - i) * pow(x, coefficients.size() - 2 - i);
    }
    return value;
}

double Polynomial::findRootNewtonRaphson(const vector<double>& coefficients, double tolerance, int maxIterations) {
    double x = 0;
    for (int i = 0; i < maxIterations; i++) {
        double fx = evaluate(coefficients, x);
        double fpx = derivative(coefficients, x);
        double nextX = x - fx / fpx;

        // Check if the next root is real
        if (isfinite(nextX)) {
            if (fabs(nextX - x) < tolerance) {
                return nextX;
            }
            x = nextX;
        } else {
            break;
        }
    }

    return std::numeric_limits<double>::quiet_NaN(); // Return NaN if no real root found
}

vector<double> Polynomial::deflate(const vector<double>& coefficients, double root) {
    vector<double> newCoefficients(coefficients.size() - 1);
    newCoefficients[0] = coefficients[0];
    counter++;
    for (int i = 1; i < newCoefficients.size(); i++) {
        newCoefficients[i] = coefficients[i] + root * newCoefficients[i - 1];
    }
    return newCoefficients;
}

vector<double> Polynomial::findAllRoots(const vector<double>& coefficients, double tolerance, int maxIterations) {
    vector<double> roots;
    vector<double> currentCoefficients = coefficients;

    while (currentCoefficients.size() > 1) {
        counter++;
        double initialGuess = 1.0;
        counter += 3;
        double root = findRootNewtonRaphson(currentCoefficients, tolerance, maxIterations);

        if (isfinite(root)) {
            roots.push_back(root);
            currentCoefficients = deflate(currentCoefficients, root);
        } else {
            break;
        }
    }

    return roots;
}

