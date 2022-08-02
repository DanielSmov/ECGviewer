#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_plottingAndBackend1.h"
#include "EcgDao.h"
#include "qcustomplot.h"

class plottingAndBackend1 : public QMainWindow
{
    Q_OBJECT

public:
    plottingAndBackend1(QWidget *parent = nullptr);
    ~plottingAndBackend1();

public slots:
    void realtimeDataSlot();
    void realtimeDataSlot1();
    void realtimeDataSlot2();

private:
    Ui::plottingAndBackend1Class ui;
    EcgDao* ecg;
    QTimer dataTimer;

    void makeEcgPlot();
    void makeElectrodePlot();
    void makePacingPlot();
};
