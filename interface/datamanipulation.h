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

//#include "Sensor.h"
//#include "IndividualPerson.h"
#include "AirCleaner.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types  

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Contenir une liste chainée de trajet et pouvoir intéragir avec
//------------------------------------------------------------------------

class Datamanipulation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void verifyAreaAirQuality(string longitude, string latitude, string radius);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
  	void verifyPointAirQuality(string longitude, string latitude);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
    void verifySensorAirQuality(string censorId);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat : 
    //
    
    void listAllSensor() const;
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    void checkImpactAirCleaner(string airCleanerId);
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

    virtual ~Datamanipulation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Datamanipulation ();
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

protected:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  //std::map<string,Sensor> myListCaptors;
  std::map<string,AirCleaner> myListAirCleaner;
  //std::map<string,IndividualPerson> myListIndividualPerson;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // DATAMANIPULATION_H