/*************************************************************************
                           Measure -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#if ! defined ( MEASURE_H )
#define MEASURE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <time.h>

#include "Attribute.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types  

//------------------------------------------------------------------------
// Rôle de la classe <Measure>
//
// Contenir une liste chainée de trajet et pouvoir intéragir avec
//------------------------------------------------------------------------

class Measure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getSensorId();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
  	time_t getTimeStamp();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    Attribute * getAttribute();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    float getValue();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    float compare(float value);
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Measure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Measure (string id, time_t time, float value, string attributeId, string unit, string description);
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

private:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string sensorId;
    time_t timeStamp;
    float value;
    Attribute * myAttribute;
};

//-------------------------------- Autres définitions dépendantes de <Measure>

#endif // MEASURE_H