//
// Created by Alexandre Senouci on 05/05/2021.
//

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/Sensor.h"
#include "../interface/Measure.h"
#include <map>

using namespace std;

//--------------------------------------------------------------- Fonction


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::getSensorID()
{
    return sensorID;
}

int Sensor::getLatitude()
{
    return latitude;
}

int Sensor::getLongitude()
{
    return longitude;
}

int Sensor::getUserID()
{
    return userID;
}

 map<> Sensor::getMeasure()
 {
    return measureList;
}

//-------------------------------------------- Constructeurs - destructeur

Sensor:: ~Sensor()
{
    #ifdef MAP
        cout << "Appel au destructeur de Sensor" << endl;
    #endif

}

Sensor::Sensor(string sensorID, int latitude, int longitude, int userID)
{
    #ifdef MAP
        cout << "Appel au constructeur de Sensor" << endl;
    #endif
    this->sensorID = sensorID;
    this->latitude = latitude;
    this->longitude = longitude;
    this->userID = userID;
}