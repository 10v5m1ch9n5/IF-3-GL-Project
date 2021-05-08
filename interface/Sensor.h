
// Created by Alexandre Senouci on 05/05/2021.
//


//---------- Interface de la classe <SENSOR> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Measure.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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

    int getUserID();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    map<std::string, Measure*> getMeasure();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void addMeasure(string id, string time, float value, string attributeId, string unit, string description);

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string sensorId, float latitude, float longitude, int userID);
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
    int userID;
    map<std::string,Measure*> myListMeasures;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H