//
// Created by Alexandre Senouci on 05/05/2021.
//

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/Sensor.h"
#include <iostream>
#include <map>

using namespace std;

//--------------------------------------------------------------- Fonction


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::getSensorID()
{
    return sensorId;
}

float Sensor::getLatitude()
{
    return latitude;
}

float Sensor::getLongitude()
{
    return longitude;
}

int Sensor::getUserID()
{
    return userID;
}

map<std::string, Measure*> Sensor::getMeasure()
{
    return myListMeasures;
}

void Sensor::addMeasure(string id, string time, float value, string attributeId, string unit, string description)
{
    Measure * myMeasure = new Measure(id, time, value, attributeId, unit, description);
    myListMeasures.insert(std::pair<string,Measure*>(time,myMeasure));
}

//-------------------------------------------- Constructeurs - destructeur

Sensor:: ~Sensor()
{
    #ifdef MAP
        cout << "Appel au destructeur de Sensor" << endl;
    #endif

}

Sensor::Sensor(string sensorID, float latitude, float longitude, int userID)
{
    #ifdef MAP
        cout << "Appel au constructeur de Sensor" << endl;
    #endif
    this->sensorId = sensorID;
    this->latitude = latitude;
    this->longitude = longitude;
    this->userID = userID;

}