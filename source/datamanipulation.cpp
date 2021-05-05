/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../interface/datamanipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::verifyAreaAirQuality(string longitude, string latitude, string radius)
{
} // ----- 

void Catalogue::verifyPointAirQuality(string longitude, string latitude)
{
} // ----- 

void Catalogue::verifySensorAirQuality(string censorId)

{
} // ----- 

void Catalogue::listAllSensor() const

{
} // ----- 

void Catalogue::checkImpactAirCleaner(string airCleanerId)

{
} // ----- 

void Catalogue::checkReliability(string userId)

{
} // ----- 


//-------------------------------------------- Constructeurs - destructeur
datamanipulation:: ~datamanipulation ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Catalogue" << endl;
	#endif
  	
}

Catalogue::Catalogue ()
{
	#ifdef MAP
	cout << "Appel au constructeur de Catalogue" << endl;
	#endif

    open
    
  	
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    