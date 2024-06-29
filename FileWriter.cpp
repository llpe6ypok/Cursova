#include "FileWriter.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void FileWriter::writeToFile(const string& filename, const vector<double>& coefficients, const vector<double>& roots, const Matrix& eigenvectors, int precision) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Помилка відкриття файлу!" << "\n\n";
        return;
    }
    outFile << fixed << setprecision(precision);
    // Запис поліному
    outFile << "Поліном має вигляд: ";
    int n = coefficients.size()-1;
    outFile << coefficients[0] << "x^" << n;
    for (int i = 0; i < n; ++i) {
        outFile << " - (" << coefficients[i+1] << "x^" << n - i - 1 << ")";
    }
    outFile << " = 0 \n\n";

    // Запис власних чисел
    outFile << "Власні числа: ";
    for (const auto& root : roots) {
        outFile << root << " ";
    }
    outFile << "\n\n";

    // Запис власних векторів
    for (int i = 0; i < roots.size(); ++i) {
        outFile << "Власний вектор " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            outFile << eigenvectors[i][j] << " ";
        }
        outFile << "\n";
    }

    outFile.close();
}
