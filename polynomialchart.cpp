#include "polynomialchart.h"
#include "ui_polynomialchart.h"

polynomialChart::polynomialChart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::polynomialChart)
{
    ui->setupUi(this);

    QLineSeries *series = new QLineSeries();
    series->append(0, 3);
    series->append(1, 5);
    series->append(2, 7);
    series->append(3, 8);
    series->append(4, 1);
    series->append(5, 5);
    series->append(6, 10);
    series->append(7, 9);
    series->append(8, 4);
    series->append(9, 3);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 12);
    chart->axes(Qt::Horizontal).first()->setRange(0, 11);
    chart->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

}

polynomialChart::~polynomialChart()
{
    delete ui;
}
