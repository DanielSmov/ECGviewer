#pragma once
#include "EcgDao.h"
#include "qcustomplot.h"

class Plot
{
public:
	void drawGraph();
	~Plot();
	
	Plot(EcgDao *ecg, QCustomPlot *parent);
private:
	QCustomPlot* mParent;

};

