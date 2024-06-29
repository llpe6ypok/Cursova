/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QRadioButton *method1RadioButton;
    QRadioButton *method2RadioButton;
    QPushButton *calculateButton;
    QRadioButton *showPolynom;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *polynom;
    QLabel *roots;
    QLabel *vectors;
    QLabel *counter;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1439, 591);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 491, 491));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(2);
        spinBox->setMaximum(8);
        spinBox->setValue(2);
        spinBox->setDisplayIntegerBase(10);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->horizontalHeader()->setMinimumSectionSize(37);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->verticalHeader()->setMinimumSectionSize(37);

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        method1RadioButton = new QRadioButton(layoutWidget);
        method1RadioButton->setObjectName("method1RadioButton");

        verticalLayout_3->addWidget(method1RadioButton);

        method2RadioButton = new QRadioButton(layoutWidget);
        method2RadioButton->setObjectName("method2RadioButton");

        verticalLayout_3->addWidget(method2RadioButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        calculateButton = new QPushButton(layoutWidget);
        calculateButton->setObjectName("calculateButton");

        verticalLayout_4->addWidget(calculateButton);

        showPolynom = new QRadioButton(centralwidget);
        showPolynom->setObjectName("showPolynom");
        showPolynom->setGeometry(QRect(70, 530, 381, 41));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(530, 40, 881, 541));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        polynom = new QLabel(layoutWidget1);
        polynom->setObjectName("polynom");

        verticalLayout_5->addWidget(polynom);

        roots = new QLabel(layoutWidget1);
        roots->setObjectName("roots");

        verticalLayout_5->addWidget(roots);

        vectors = new QLabel(layoutWidget1);
        vectors->setObjectName("vectors");

        verticalLayout_5->addWidget(vectors);

        counter = new QLabel(layoutWidget1);
        counter->setObjectName("counter");

        verticalLayout_5->addWidget(counter);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(540, 10, 371, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \320\262\320\273\320\260\321\201\320\275\320\270\321\205 \321\207\320\270\321\201\320\265\320\273 \321\202\320\260 \320\262\320\273\320\260\321\201\320\275\320\270\321\205 \320\262\320\265\320\272\321\202\320\276\321\200\321\226\320\262", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \321\200\320\276\320\267\320\274\321\226\321\200 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\270\321\207\320\275\320\276\321\227 \320\274\320\260\321\202\321\200\320\270\321\206\321\226", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\262\320\275\320\270\321\202\320\270 \320\262\320\270\320\277\320\260\320\264\320\272\320\276\320\262\320\276", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\271\320\275\321\217\321\202\320\270 \320\267\320\260\320\277\320\276\320\262\320\275\320\265\320\275\320\275\321\217", nullptr));
        method1RadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\232\321\200\320\270\320\273\320\276\320\262\320\260", nullptr));
        method2RadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\233\320\265\320\262\320\265\321\200\321\200\321\214\320\265-\320\244\320\265\320\264\321\224\321\224\320\262\320\260", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270", nullptr));
        showPolynom->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\321\207\320\275\320\270\320\271 \320\263\321\200\320\260\321\204\321\226\320\272 \320\277\320\276\320\273\321\226\320\275\320\276\320\274\320\260", nullptr));
        polynom->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\261\321\203\320\264\320\265 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\320\270\320\271 \320\277\320\276\320\273\321\226\320\275\320\276\320\274", nullptr));
        roots->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\261\321\203\320\264\321\203\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\321\226 \320\262\320\273\320\260\321\201\320\275\321\226 \321\207\320\270\321\201\320\273\320\260", nullptr));
        vectors->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\261\321\203\320\264\321\203\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\321\226 \320\262\320\273\320\260\321\201\320\275\321\226 \320\262\320\265\320\272\321\202\320\276\321\200\320\270", nullptr));
        counter->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\321\202 \320\261\321\203\320\264\320\265 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\275\321\226\321\201\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\200\320\276\320\261\320\276\321\202\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
