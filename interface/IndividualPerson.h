/*************************************************************************
                           IndividualPerson -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <IndividualPerson> (fichier IndividualPerson.h) ----------------
#if ! defined ( IndividualPerson_H )
#define IndividualPerson_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <time.h>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types  

//------------------------------------------------------------------------
// Rôle de la classe <IndividualPerson>
//
// Contenir une liste chainée de trajet et pouvoir intéragir avec
//------------------------------------------------------------------------

class IndividualPerson
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
  	int getScore();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    bool getReliability();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    void addScore();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    string getId();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    virtual ~IndividualPerson ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    IndividualPerson (string id);
    // Mode d'emploi (constructeur de copie) : 
    //
    // Contrat : 
    //

//------------------------------------------------------------------ PRIVE

private:

  
  
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    string userId;
    int score;
    bool reliability;
};

//-------------------------------- Autres définitions dépendantes de <IndividualPerson>

#endif // IndividualPerson_H