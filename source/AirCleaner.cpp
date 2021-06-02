/*************************************************************************
                           AirCleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/AirCleaner.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

float AirCleaner::getLatitude()
{
    return latitude;
}

    
float AirCleaner::getLongitude()
{
    return longitude;
}


time_t AirCleaner::getTimeStampStart()
{
    return timeStampStart;
}


time_t AirCleaner::getTimeStampStop()
{
    return timeStampStop;
}
    
string AirCleaner::getId()
{
    return cleanerId;
}

//-------------------------------------------- Constructeurs - destructeur
AirCleaner:: ~AirCleaner ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de AirCleaner" << endl;
	#endif
  	
}

AirCleaner::AirCleaner (string id, float lat, float longi, time_t start, time_t stop,string nomEntreprise)
{
	#ifdef MAP
	cout << "Appel au constructeur de AirCleaner" << endl;
	#endif
    cleanerId=id;
    latitude=lat;
    longitude=longi;
    timeStampStop=stop;
    timeStampStart=start;
    this->nomEntreprise=nomEntreprise;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    