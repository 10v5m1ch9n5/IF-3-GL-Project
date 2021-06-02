
// Created by Alexandre Senouci on 05/05/2021.
//


//---------- Interface de la classe <SENSOR> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Measure.h"
#include <time.h>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum airQuality {VeryGood, Good, Average, Poor, Bad,VeryBad};

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    float getLatitude();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    float getLongitude();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getSensorID();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getUserID();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    multimap<time_t, Measure*> getMeasure();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    float getAirQuality(time_t time);

    void addMeasure(string id, time_t time, float value, string attributeId, string unit, string description);

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string sensorId, float latitude, float longitude, string userID);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:



//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string sensorId;
    float latitude;
    float longitude;
    string userID;
    multimap<time_t,Measure*> myListMeasures;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H