
// Created by Alexandre Senouci on 05/05/2021.
//


//---------- Interface de la classe <SENSORr> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
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
    string getLatitude();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getLongitude();
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
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string id, string lat, string longi, string start, string stop);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:



//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    String SensorID;
    int Latitude;
    int Longitude;
    int UserID
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H