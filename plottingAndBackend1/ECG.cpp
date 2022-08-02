#include "ECG.h"
ECG::ECG() {
	//ECG constructor method

}
ECG::~ECG() {
	//ECG destructor method
}

QVector<double> ECG::getVEcg_data() {
	/*get method for the vEcg_data attribute
	  returns a vector<float> type object
	*/
	return this->vEcg_data;
}
QVector<double> ECG::getVElectrode_data() {
	/*get method for the vElectrode_data attribute
	  returns a vector<float> type object
	*/
	return this->vElectrode_data;
}
QVector<double> ECG::getVPacing_data() {
	/*get method for the vPacing_data attribute
	  returns a vector<float> type object
	*/
	return this->vPacing_data;
}

void ECG::setVEcg_data(QVector<double> &data) {
	/*set method for the vEcg_data attribute
	  receives as parameter vector<float> type object
	  */
	this->vEcg_data = data;
}
void ECG::setVElectrode_data(QVector<double> &data) {
	/*set method for the vElectrode_data attribute
	  receives as parameter vector<float> type object
	  */
	this->vElectrode_data = data;
}
void ECG::setVPacing_data(QVector<double> &data) {
	/*set method for the vPacing_data attribute
	  receives as parameter vector<float> type object
	  */
	this->vPacing_data = data;
}