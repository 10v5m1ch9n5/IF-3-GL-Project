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

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measure::getMeasureId()
{
    return measureId;
}
    
string Measure::getTimeStamp()
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


int Measure::compare()
{

}
    
//-------------------------------------------- Constructeurs - destructeur
Measure:: ~Measure ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Measure" << endl;
	#endif
  	delete(myAttribute);
}

Measure::Measure (string id, string time, float value, string attributeId, string unit, string description)
{
	#ifdef MAP
	cout << "Appel au constructeur de Measure" << endl;
	#endif
    measureId=id;
    timeStamp=time;
    this->value=value;
    myAttribute = new Attribute(attributeId, unit, description, this);
    
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    