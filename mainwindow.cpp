#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "counter.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setRange(2, 8);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateTableSize(int)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(saveToVector())); //заповнення масиву
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked())); //заповнення таблиці випадковими числами.

    updateTableSize(ui->spinBox->value());

    srand(time(0));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTableSize(int size)
{
    ui->tableWidget->clear();
    data.clear();
    data.shrink_to_fit();
    ui->calculateButton->setEnabled(false); //для того, аби неможливо було почату обрахунок без заповненого масиву

    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem();
            ui->tableWidget->setItem(i, j, item);
        }
    }
}


double determinant(const vector<vector<double>>& matrix, int n) {
    vector<vector<double>> a = matrix;
    double det = 1;

    for (int i = 0; i < n; i++) {
        // Пошук максимального елемента у стовбці для поліпшенння стабільності
        double maxElement = abs(a[i][i]);
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > maxElement) {
                maxElement = abs(a[j][i]);
                maxRow = j;
            }
        }

        // Зміна місцями поточного рядка зі знайденим рядком з максимальним елементом
        if (i != maxRow) {
            swap(a[i], a[maxRow]);
            det = -det;  // Зміна знаку визначника при зміні рядків
        }

        // Якщо елемент на діагоналі дорівнює нулю, то визначник теж дорівнює нулю
        if (a[i][i] == 0) {
            return 0;
        }

        // Переведення матриці до верхньотрикутної
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Визначник дорівнює результату множення діагональних елементів верхньотрикутної матриці
    for (int i = 0; i < n; ++i) {
        det *= a[i][i];
    }

    return det;
}

void MainWindow::saveToVector() {
    int n = ui->spinBox->value();

    data.resize(n, vector<double>(n, 1.0));

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        for (int j = 0; j < n && ok; j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item) {
                bool cellOk;
                double value = item->text().toDouble(&cellOk);
                if (cellOk && (value > -100.0 && value < 100.0)) {
                    data[i][j] = value;
                } else {
                    ok = false;
                }
            } else {
                ok = false;
            }
        }
    }

    if (ok) {
        double det = determinant(data, n);
        if (det == -1.0 || det == 0.0 || det == 1.0) {
            QMessageBox::critical(this, "Помилка", "Визначник не повинен дорівнювати -1, 0, або 1!");
        } else {
            ui->calculateButton->setEnabled(true);
            QMessageBox::information(this, "Успіх", "Значення успішно перенесено!");
        }
    } else {
        QMessageBox::critical(this, "Помилка", "Некорректні дані введені в таблицю!");
    }
}

void MainWindow::calculate()
{

    // Перетворення data у Matrix
    int size = ui->spinBox->value();
    Matrix matrix(size);
    matrix.matrixSetValue(data);
    int _precision = 4;
    vector<double> coefficients(size, 0);
    unique_ptr<Solver> solver;
    vector<double> roots;

    if (ui->method1RadioButton->isChecked()) {
        solver = make_unique<KrylovMethodSolver>(matrix);
        coefficients = Calculation(matrix, _precision, size, solver, roots);
    } else if (ui->method2RadioButton->isChecked()) {
        solver = make_unique<LevereMethodSolver>(matrix);
        coefficients = Calculation(matrix, _precision, size, solver, roots);
    } else {
        QMessageBox::critical(this, "Помилка", "Не вибрано жодного методу!");
    }

    if(ui->showPolynom->isChecked()){
        PolynomialGraphs *graphWindow = new PolynomialGraphs(coefficients, roots);
        graphWindow->exec();
    }
}

vector<double> MainWindow::Calculation(Matrix matrix, int _precision, int size, unique_ptr<Solver>& solver, vector<double>& roots)
{
    // Виконання розрахунку
    vector<double> p = solver->getP();

    vector<double> _coefficients(size + 1, 1.0);
    for (int i = 1; i <= size; i++) {
        _coefficients[i] = p[i - 1];
    }

    if((_coefficients.size() + 1) % 2 != 0)
    {
        for(int i = 0; i < _coefficients.size(); i++){
            _coefficients[i] *= -1.;
        }
    }

    QString vectorText;
    vectorText += "Поліном має вигляд:" + QString::number(_coefficients[0]) + "l^" + QString::number(size);
    for (int i = 0; i < size; i++) {

        vectorText += "-(" + QString::number(_coefficients[i+1], 'f', _precision) + "l^" + QString::number(size-i-1) + ")";
    }
    vectorText += " = 0\n";
    ui->polynom->setText(vectorText);

    vectorText = "";
    roots = solver->getEigenvalues();
    vectorText += "Власні числа: ";
    for (int i = 0; i < roots.size(); i++) {

        vectorText += QString::number(roots[i], 'f', _precision) + " | ";
    }
    vectorText += "\n";
    ui->roots->setText(vectorText);


    vectorText = "";
    Matrix eigenvectors = solver->getEigenVectors(roots);
    for (int i = 0; i < roots.size(); i++) {
        vectorText += "Власний вектор " + QString::number(i+1) + ": ";
        for (int j = 0; j < size; j++) {
            vectorText += QString::number(eigenvectors[i][j], 'f', _precision) + " | ";
        }
        vectorText += "\n";
    }
    ui->vectors->setText(vectorText);

    vectorText = "";
    vectorText += "Складність: " + QString::number(counter);
    ui->counter->setText(vectorText);
    counter = 0;

    //запис результатів до файлу
    FileWriter _fileWriter;
    _fileWriter.writeToFile("output.txt", _coefficients, roots, eigenvectors, _precision);

    return _coefficients;
}

void MainWindow::on_pushButton_2_clicked()
{
    int size = ui->tableWidget->rowCount();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double randomValue = 1.0 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (10.0 - 1.0)));
            ui->tableWidget->item(i, j)->setText(QString::number(randomValue));
        }
    }
}

