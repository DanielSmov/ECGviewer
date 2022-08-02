/********************************************************************************
** Form generated from reading UI file 'plottingAndBackend1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTINGANDBACKEND1_H
#define UI_PLOTTINGANDBACKEND1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_plottingAndBackend1Class
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot1;
    QCustomPlot *customPlot2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *plottingAndBackend1Class)
    {
        if (plottingAndBackend1Class->objectName().isEmpty())
            plottingAndBackend1Class->setObjectName(QString::fromUtf8("plottingAndBackend1Class"));
        plottingAndBackend1Class->resize(748, 580);
        centralWidget = new QWidget(plottingAndBackend1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 40, 531, 131));
        customPlot1 = new QCustomPlot(centralWidget);
        customPlot1->setObjectName(QString::fromUtf8("customPlot1"));
        customPlot1->setGeometry(QRect(10, 200, 531, 131));
        customPlot2 = new QCustomPlot(centralWidget);
        customPlot2->setObjectName(QString::fromUtf8("customPlot2"));
        customPlot2->setGeometry(QRect(10, 370, 531, 131));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 180, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 350, 47, 13));
        plottingAndBackend1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(plottingAndBackend1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 748, 21));
        plottingAndBackend1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(plottingAndBackend1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        plottingAndBackend1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(plottingAndBackend1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        plottingAndBackend1Class->setStatusBar(statusBar);

        retranslateUi(plottingAndBackend1Class);

        QMetaObject::connectSlotsByName(plottingAndBackend1Class);
    } // setupUi

    void retranslateUi(QMainWindow *plottingAndBackend1Class)
    {
        plottingAndBackend1Class->setWindowTitle(QCoreApplication::translate("plottingAndBackend1Class", "plottingAndBackend1", nullptr));
        label->setText(QCoreApplication::translate("plottingAndBackend1Class", "ECG", nullptr));
        label_2->setText(QCoreApplication::translate("plottingAndBackend1Class", "Electrode", nullptr));
        label_3->setText(QCoreApplication::translate("plottingAndBackend1Class", "Pacing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plottingAndBackend1Class: public Ui_plottingAndBackend1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTINGANDBACKEND1_H
