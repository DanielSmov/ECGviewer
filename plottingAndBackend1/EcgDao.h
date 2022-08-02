#pragma once
#include "ECG.h"
class EcgDao
{
private:
	ECG ecg;
public:
	EcgDao();
	~EcgDao();

	ECG getEcg();
	void setEcg(ECG &ecg);
	void loadData();
};

