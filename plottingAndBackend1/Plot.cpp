#include "Plot.h"

void Plot::drawGraph()
{
}

Plot::~Plot()
{
}

Plot::Plot(EcgDao* ecg, QCustomPlot* parent)
{
	this->ecg = ecg;
	this->mParent = parent;
}
