#include "polynomialgraphs.h"
#include "ui_polynomialgraphs.h"
#include <QtMath>

PolynomialGraphs::PolynomialGraphs(const std::vector<double> &cofficient, std::vector<double>& roots, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PolynomialGraphs)
{
    ui->setupUi(this);

    // Create series for the polynomial graph
    QLineSeries *series = new QLineSeries();
    int size = cofficient.size() - 1;

    std::vector<double> root = roots;
    std::sort(root.begin(), root.end());

    // Determine the x-axis range based on the roots
    double minX = root.front() - 10.0;
    double maxX = root.back() + 10.0;

    double x = minX;
    while(x <= maxX)
    {
        double y = qPow(x, size);
        if (size % 2 != 0) {
            y *= -1.;
        }

        for (int i = 1; i <= size; i++) {
            y += qPow(x, size - i) * (-1 * cofficient[i]);
        }
        series->append(x, y);
        x += 0.1;
    }
    // Create series for the x-axis line
    QLineSeries *axisX = new QLineSeries();
    axisX->append(minX, 0);
    axisX->append(maxX, 0);

    // Create series for the y-axis line
    QLineSeries *axisY = new QLineSeries();
    axisY->append(0, -250);
    axisY->append(0, 250);

    // Create the chart and set properties
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(axisX); // Add x-axis line
    chart->addSeries(axisY); // Add y-axis line
    chart->addSeries(series); // Add polynomial series
    chart->createDefaultAxes(); // Create default axes
    chart->axes(Qt::Vertical).first()->setRange(-250, 250); // Set y-axis range
    chart->axes(Qt::Horizontal).first()->setRange(minX, maxX); // Set x-axis range

    // Customize the appearance of axis lines
    QPen axisPen(Qt::black, 2, Qt::SolidLine); // Pen for axis lines
    axisPen.setCosmetic(true); // Ensure the pen is cosmetic

    // Set the pen for the x-axis line
    axisX->setPen(axisPen);

    // Set the pen for the y-axis line
    axisY->setPen(axisPen);

    // Create ChartView and set it as central widget
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this); // Use QVBoxLayout to set chartView as central widget
    layout->addWidget(chartView);
    setLayout(layout);
}

PolynomialGraphs::~PolynomialGraphs()
{
    delete ui;
}

