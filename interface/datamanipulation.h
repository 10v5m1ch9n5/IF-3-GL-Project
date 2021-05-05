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
    void VerifyAirQuality(string ) { return liste; }
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    
  	void newTrajet(Trajet * & trajet);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : ajoute un élément à la fin de la liste chainée de trajet
    //
    // Contrat : 
    //
    
    void showCatalogue();
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : utilise les méthodes toString de la classe trajet pour afficher les différents Trajets
    //
    // Contrat : 
    //
    
    void rechercherTrajet(char * lieuDepart, char * lieuArrive) const;
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : Compare les paramètres fournis en argument de la fonction avec les attributs de chaque chainon composant la liste chainée
    //
    // Contrat : 
    //

    void rechercherTrajetAvance(Trajet ** chemin, int nbr, char * lieuDepart, char * lieuArrive);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    void import(int type, string lieuDepart, string lieuArrive, ifstream& input);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    void exportDataAll(string dest);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    void exportDataFilterByTrajet(int,string dest);
    // void type Méthode ( liste des paramètres );
    // Mode d'emploi : 
    //
    // Contrat : 
    //
    void exportDataaFilterByCity(string villeArrive, string villeDepart, string dest);
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
  ListeChaineeTrajet * liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // DATAMANIPULATION_H