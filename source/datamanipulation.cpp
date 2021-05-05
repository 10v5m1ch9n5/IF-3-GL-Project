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

//------------------------------------------------------ Include personnel
#include "../interface/datamanipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::verifyAreaAirQuality(string longitude, string latitude)
{
} // ----- 

void Catalogue::verifyPointAirQuality(string longitude, string latitude)
{
} // ----- 

void Catalogue::verifyAreaAirQuality(string longitude, string latitude)
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
  
  	
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    