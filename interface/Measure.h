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

#include "Attribute.h"
#include "Sensor.h"

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
    string getMeasureId();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
  	string getTimeStamp();
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

    int compare();
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~Measure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Measure (string id, string time, float value, string attributeId, string unit, string description, Sensor * sensor);
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

private:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string measureId;
    string timeStamp;
    float value;
    Attribute * myAttribute;
    Sensor * mySensor;
};

//-------------------------------- Autres définitions dépendantes de <Measure>

#endif // MEASURE_H