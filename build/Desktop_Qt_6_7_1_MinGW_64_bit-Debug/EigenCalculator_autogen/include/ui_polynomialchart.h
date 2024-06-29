/********************************************************************************
** Form generated from reading UI file 'polynomialchart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYNOMIALCHART_H
#define UI_POLYNOMIALCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_polynomialChart
{
public:

    void setupUi(QDialog *polynomialChart)
    {
        if (polynomialChart->objectName().isEmpty())
            polynomialChart->setObjectName("polynomialChart");
        polynomialChart->resize(520, 471);

        retranslateUi(polynomialChart);

        QMetaObject::connectSlotsByName(polynomialChart);
    } // setupUi

    void retranslateUi(QDialog *polynomialChart)
    {
        polynomialChart->setWindowTitle(QCoreApplication::translate("polynomialChart", "Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class polynomialChart: public Ui_polynomialChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYNOMIALCHART_H
