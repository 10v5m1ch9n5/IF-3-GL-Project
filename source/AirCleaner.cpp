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

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int AirCleaner::getLatitude()
{
    return latitude;
}

    
int AirCleaner::getLongitude()
{
    return longitude;
}


string AirCleaner::getTimeStampStart()
{
    return timeStampStart;
}


string AirCleaner::getTimeStampStop()
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

AirCleaner::AirCleaner (string id, float lat, float longi, string start, string stop,string nomEntreprise)
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
    