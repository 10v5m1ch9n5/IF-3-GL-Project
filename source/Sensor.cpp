//
// Created by Alexandre Senouci on 05/05/2021.
//

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/Sensor.h"

using namespace std;

//--------------------------------------------------------------- Fonction


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::getSensorID()
{
    return SensorID
}

int Sensor::getLatitude()
{
    return Latitude
}

int Sensor::getLongitude()
{
    return Longitude
}

int Sensor::getUserID()
{
    return UserID
}