#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "polynomialgraphs.h"
#include <QMessageBox>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "KrylovMethodSolver.h"
#include "LevereMethodSolver.h"
#include "Matrix.h"
#include "FileWriter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTableSize(int size);
    void saveToVector();
    void calculate();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    vector<vector<double>> data;

    vector<double> Calculation(Matrix matrix, int _precision, int size, unique_ptr<Solver>& solver, vector<double>& roots);
};

#endif // MAINWINDOW_H

