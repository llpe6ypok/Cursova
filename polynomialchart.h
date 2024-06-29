#ifndef POLYNOMIALCHART_H
#define POLYNOMIALCHART_H

#include <QDialog>
#include <QtWidgets>
#include <QtCharts>

namespace Ui {
class polynomialChart;
}

class polynomialChart : public QDialog
{
    Q_OBJECT

public:
    explicit polynomialChart(QWidget *parent = nullptr);
    ~polynomialChart();

private:
    Ui::polynomialChart *ui;
};

#endif // POLYNOMIALCHART_H
