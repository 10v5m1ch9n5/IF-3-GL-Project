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

int getAirQualityPM10(float value)
{
    if(0<value<=6)
    {
        return 1;
    }
    else if(value<=13)
    {
        return 2;
    }
    else if(value<=20)
    {
        return 3;
    }
    else if(value<=27)
    {
        return 4;
    }
    else if(value<=34)
    {
        return 5;
    }
    else if(value<=41)
    {
        return 6;
    }
    else if(value<=49)
    {
        return 7;
    }
    else if(value<=64)
    {
        return 8;
    }
    else if(value<=79)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int getAirQualitySO2(float value)
{
    if(0<value<=39)
    {
        return 1;
    }
    else if(value<=79)
    {
        return 2;
    }
    else if(value<=119)
    {
        return 3;
    }
    else if(value<=159)
    {
        return 4;
    }
    else if(value<=199)
    {
        return 5;
    }
    else if(value<=249)
    {
        return 6;
    }
    else if(value<=299)
    {
        return 7;
    }
    else if(value<=399)
    {
        return 8;
    }
    else if(value<=499)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int getAirQualityO3(float value)
{
    if(0<value<=29)
    {
        return 1;
    }
    else if(value<=54)
    {
        return 2;
    }
    else if(value<=79)
    {
        return 3;
    }
    else if(value<=104)
    {
        return 4;
    }
    else if(value<=129)
    {
        return 5;
    }
    else if(value<=149)
    {
        return 6;
    }
    else if(value<=179)
    {
        return 7;
    }
    else if(value<=209)
    {
        return 8;
    }
    else if(value<=239)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int getAirQualityNO2(float value)
{
    if(0<value<=29)
    {
        return 1;
    }
    else if(value<=54)
    {
        return 2;
    }
    else if(value<=84)
    {
        return 3;
    }
    else if(value<=109)
    {
        return 4;
    }
    else if(value<=134)
    {
        return 5;
    }
    else if(value<=164)
    {
        return 6;
    }
    else if(value<=199)
    {
        return 7;
    }
    else if(value<=274)
    {
        return 8;
    }
    else if(value<=399)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::getSensorID()
{
    return sensorId;
}

airQuality Sensor::getAirQuality(string timeStart, string timeStop)
{

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


multimap<std::string, Measure*> Sensor::getMeasure()
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