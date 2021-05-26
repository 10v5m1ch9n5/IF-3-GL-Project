/*************************************************************************
                           Measure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/Measure.h"
#include "../interface/Sensor.h"

#include <iostream>
using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measure::getSensorId()
{
    return sensorId;
}
    
time_t Measure::getTimeStamp()
{
    return timeStamp;
}

Attribute * Measure::getAttribute()
{
    return myAttribute;
}

float Measure::getValue()
{
    return value;
}


float Measure::compare(float otherValue)
{
    return value - otherValue;
}
    
//-------------------------------------------- Constructeurs - destructeur
Measure:: ~Measure ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Measure" << endl;
	#endif
  	delete(myAttribute);
}

Measure::Measure (string id, time_t time, float value, string attributeId, string unit, string description)
{
	#ifdef MAP
	cout << "Appel au constructeur de Measure" << endl;
	#endif
    //cout<<id<<" "<<time<<" "<<value<<" "<<attributeId<<" "<<unit<<" "<<description<<endl;
    sensorId=id;
    timeStamp=time;
    this->value=value;
    myAttribute = new Attribute(attributeId, unit, description);
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    
