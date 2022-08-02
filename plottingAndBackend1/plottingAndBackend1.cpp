#include "plottingAndBackend1.h"

plottingAndBackend1::plottingAndBackend1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //initializes the ecgDao object
    ecg = new EcgDao();
    //loads data into object
    ecg->loadData();
    
    //creates Ecg plot
    makeEcgPlot();
    //creates Electode plot
    makeElectrodePlot();
    //creates Pacing plot
    makePacingPlot();
}

plottingAndBackend1::~plottingAndBackend1()
{
    delete ecg;
}

void plottingAndBackend1::makeEcgPlot()
{
    //adds the Graph to the widget
    ui.customPlot->addGraph(); // red line
    ui.customPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));

    //sets the x axis displayed information, uses a ticker to show time
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    ui.customPlot->xAxis->setTicker(timeTicker);
    //sets the upper and right axis
    ui.customPlot->axisRect()->setupFullAxesBox();
    //sets the yAxis 
    ui.customPlot->yAxis->setRange(-0.0005, 0.0003);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui.customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui.customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(1); // Interval 0 means to refresh as fast as possible
}

void plottingAndBackend1::makeElectrodePlot()
{
    //adds the Graph to the widget
    ui.customPlot1->addGraph();
    ui.customPlot1->graph(0)->setPen(QPen(QColor(255, 0, 0)));

    //sets the x axis displayed information, uses a ticker to show time
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    ui.customPlot1->xAxis->setTicker(timeTicker);
    //sets the upper and right axis
    ui.customPlot1->axisRect()->setupFullAxesBox();
    ui.customPlot1->yAxis->setRange(-0.006, 0.004);


    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui.customPlot1->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot1->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui.customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot1->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot1()));
    dataTimer.start(1); // Interval 0 means to refresh as fast as possible
}

void plottingAndBackend1::makePacingPlot()
{
    //adds the Graph to the widget
    ui.customPlot2->addGraph(); // violet line
    ui.customPlot2->graph(0)->setPen(QPen(QColor(255, 0, 0)));

    //sets the x axis displayed information, uses a ticker to show time
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    ui.customPlot2->xAxis->setTicker(timeTicker);
    //sets the upper and right axis
    ui.customPlot2->axisRect()->setupFullAxesBox();
    ui.customPlot2->yAxis->setRange(-0.07, 0.2);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui.customPlot2->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot2->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui.customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.customPlot2->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot2()));
    dataTimer.start(1); // Interval 0 means to refresh as fast as possible
}

void plottingAndBackend1::realtimeDataSlot() {

    static QTime time(QTime::currentTime()); // gets time since the application started running
    double key = time.elapsed() / 1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0; //saves the last key value
    static int i = 0; //counter to move the values in the QVector

    if (key - lastPointKey > 0.001) // at most add point every 1 ms
    {
        //adds to the customPlot, on the graph 0, the ECG data 
        ui.customPlot->graph(0)->addData(key, ecg->getEcg().getVEcg_data().at(i));
        //updates the lastPointKey
        lastPointKey = key;
        //increases i by 1
        ++i;

        //if the counter reaches the end of the vector, restarts the counter at 0.
        if (i == ecg->getEcg().getVEcg_data().size())
            i = 0;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui.customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    // draws the plot 
    ui.customPlot->replot();
}

void plottingAndBackend1::realtimeDataSlot1()
{
    static QTime time(QTime::currentTime()); // gets time since the application started running
    double key = time.elapsed() / 1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0; //saves the last key value
    static int i = 0; //counter to move the values in the QVector

    if (key - lastPointKey > 0.001) // at most add point every 2 ms
    {
        //adds to the customPlot, on the graph 0, the Electrode data
        ui.customPlot1->graph(0)->addData(key, ecg->getEcg().getVElectrode_data().at(i));
        //updates the lastPointKey
        lastPointKey = key;
        //increases i by 1
        ++i;
        //if the counter reaches the end of the vector, restarts the counter at 0.
        if (i == ecg->getEcg().getVElectrode_data().size())
            i = 0;
    }


    // make key axis range scroll with the data (at a constant range size of 8):
    ui.customPlot1->xAxis->setRange(key, 8, Qt::AlignRight);
    ui.customPlot1->replot();
}

void plottingAndBackend1::realtimeDataSlot2()
{
    static QTime time(QTime::currentTime()); // time elapsed since start of demo, in seconds
    double key = time.elapsed() / 1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0; //saves the last key value
    static int i = 0; //counter to move the values in the QVector

    if (key - lastPointKey > 0.001) // at most add point every 2 ms
    {
        //adds to the customPlot, on the graph 0, the Pacing data
        ui.customPlot2->graph(0)->addData(key, ecg->getEcg().getVPacing_data().at(i));
        //updates the lastPointKey
        lastPointKey = key;
        //increases i by 1
        ++i;

        if (i == ecg->getEcg().getVPacing_data().size())
            i = 0;
    }

    // make key axis range scroll with the data (at a constant range size of 8):
    ui.customPlot2->xAxis->setRange(key, 8, Qt::AlignRight);
    ui.customPlot2->replot();
}
