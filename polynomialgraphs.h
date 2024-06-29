#ifndef POLYNOMIALGRAPHS_H
#define POLYNOMIALGRAPHS_H

#include <QDialog>
#include <QtCharts>
#include <QVBoxLayout>
#include <vector>

namespace Ui {
class PolynomialGraphs;
}

class PolynomialGraphs : public QDialog
{
    Q_OBJECT

public:
    explicit PolynomialGraphs(const std::vector<double>& cofficient, std::vector<double>& roots, QWidget *parent = nullptr);
    ~PolynomialGraphs();

private:
    Ui::PolynomialGraphs *ui;
};

#endif

