#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <vector>
#include "Matrix.h"

using namespace std;

class FileWriter {
public:
    void writeToFile(const string& filename, const vector<double>& coefficients, const vector<double>& roots, const Matrix& eigenvectors, int precision);
};

#endif
