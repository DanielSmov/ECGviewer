#include "EcgDao.h"
#include <fstream>
#include <string>

using namespace std;

EcgDao::EcgDao() {
   //Ecg Data Object constructor method
}
EcgDao::~EcgDao() {
    //Ecg Data Object destructor method
}

ECG EcgDao::getEcg() {
    /*get method for the ECG attribute
    returns an ECG type object*/
    return this->ecg;
}
void EcgDao::setEcg(ECG &ecg) {
    /*set method for ECG attribute
    receives as parameter an ECG type object*/
    this->ecg = ecg;
}
void EcgDao::loadData() {
    /*The loadData() method reads the .txt files that contain the data,
      then loads the data into vectors that hold float values, and
      assigns the vectors to the ECG object attributes using the set methods
    */

    //creates an fstream object
    fstream file;
    //creates a vector objectthat holds float values
    QVector<double> data;

    //opens the ecg_data.txt file
    file.open("ecg_data.txt", ios::in); //opens a file to perform 
    if (file.is_open()) {
        //creates string that will hold the values
        string text;
        //reads data from file object and places it into the string
        while (getline(file, text)) {
            //parses from string to float value
            float value = stod(text.c_str());
            //pushes value into the vector
            data.push_back(value);
            //this->ecg.setVEcg_data(data);
        }
        //passes the data vector as a parameter to the setEcg method
        this->ecg.setVEcg_data(data);
        //close the ecg_data.txt file
        file.close();
    }
    //clears the data vector
    data.clear();

    //opens the electrode_data.txt file
    file.open("electrode_data.txt", ios::in); //opens a file to perform 
    if (file.is_open()) {
        string text;
        //reads data from file object and places it into the string
        while (getline(file, text)) {
            //parses from string to float value
            float value = stod(text.c_str());
            //pushes value into the vector
            data.push_back(value);
        }
        //passes the data vector as a parameter to the setElectrode method
        this->ecg.setVElectrode_data(data);
        file.close();
    }
    //clears the data vector
    data.clear();

    //opens the pacing_data.txt file
    file.open("pacing_data.txt", ios::in); //opens a file to perform read 
    if (file.is_open()) {
        string text;
        //reads data from file object and places it into the string
        while (getline(file, text)) {
            //parses from string to float value
            float value = stod(text.c_str());
            //pushes value into the vector
            data.push_back(value);
        }
        //passes the data vector as a parameter to the setPacing method
        this->ecg.setVPacing_data(data);
        file.close();
    }
}