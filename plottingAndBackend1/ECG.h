#pragma once
#include<QVector>
using namespace std;

class ECG
{
    
private:
    QVector<double> vEcg_data;
    QVector<double> vElectrode_data;
    QVector<double> vPacing_data;

public:
    ECG();
    ~ECG();

    QVector<double> getVEcg_data();
    QVector<double> getVElectrode_data();
    QVector<double> getVPacing_data();

    void setVEcg_data(QVector<double> &data);
    void setVElectrode_data(QVector<double> &data);
    void setVPacing_data(QVector<double> &data);
};
