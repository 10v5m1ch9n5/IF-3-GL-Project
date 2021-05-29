/*************************************************************************
                           Datamanipulation -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DATAMANIPULATION> (fichier datamanipulation.h) ----------------
#if ! defined ( DATAMANIPULATION_H )
#define DATAMANIPULATION_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>

#include "Sensor.h"
//#include "IndividualPerson.h"
#include "AirCleaner.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types  

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Contenir une liste chainée de trajet et pouvoir intéragir avec
//------------------------------------------------------------------------

class DataManipulation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int verifyAreaAirQuality(float longitude, float latitude, float radius, time_t time);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
  	void verifyPointAirQuality(float longitude, float latitude);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
    void findSimilarSensor(string sensorId);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat : 
    //
    
    void listAllSensor();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    pair<int,int> checkImpactAirCleaner(string airCleanerId, float radius);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    float checkImpactedRadiusAirCleaner(string airCleanerId);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    void checkReliability(string userId);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~DataManipulation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    DataManipulation ();
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

protected:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  std::map<string,Sensor*> myListSensors;
  std::map<string,AirCleaner*> myListAirCleaner;
  //std::map<string,IndividualPerson> myListIndividualPerson;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // DATAMANIPULATION_H
