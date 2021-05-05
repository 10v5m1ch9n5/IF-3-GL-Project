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

map<Measure> getMeasure()
{

}

//-------------------------------------------- Constructeurs - destructeur

Sensor:: ~Sensor()
{
    #ifdef MAP
        cout << "Appel au destructeur de Sensor" << endl;
    #endif

}

Sensor::Sensor(string sid, int lat, int lon, int uid)
{
    #ifdef MAP
        cout << "Appel au constructeur de Sensor" << endl;
    #endif
    sensorID = sid;
    latitude = lat;
    longitude = lon;
    userID = uid;
}