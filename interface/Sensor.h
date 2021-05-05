
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
    int getLatitude();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int getLongitude();
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

   map<string, Measure> getMeasure();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string sensorID, int latitude, int longitude, int userID);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:



//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string sensorID;
    int latitude;
    int longitude;
    int userID;
    map<string,Measure> measureList;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H