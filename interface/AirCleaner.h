/*************************************************************************
                           AirCleaner -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AIRCLEANER> (fichier AirCleaner.h) ----------------
#if ! defined ( AIRCLEANER_H )
#define AIRCLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <time.h>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types  

//------------------------------------------------------------------------
// Rôle de la classe <AirCleaner>
//
// Contenir une liste chainée de trajet et pouvoir intéragir avec
//------------------------------------------------------------------------

class AirCleaner
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

    time_t getTimeStampStart();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    time_t getTimeStampStop();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    string getId();
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~AirCleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirCleaner (string id, float lat, float longi, time_t start, time_t stop, string nomEntreprise="");
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

private:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string cleanerId;
    float latitude;
    float longitude;
    time_t timeStampStart;
    time_t timeStampStop;
    string nomEntreprise;
};

//-------------------------------- Autres définitions dépendantes de <AirCleaner>

#endif // AIRCLEANER_H