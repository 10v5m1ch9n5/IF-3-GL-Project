/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/Attribute.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Attribute::getAttributeId()
{
    return attributeId;
}

    
string Attribute::getUnit()
{
    return unit;
}


string Attribute::getDescription()
{
    return description;
}

//-------------------------------------------- Constructeurs - destructeur
Attribute:: ~Attribute ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Attribute" << endl;
	#endif
  	
}

Attribute::Attribute (string id, string unit, string description)
{
	#ifdef MAP
	cout << "Appel au constructeur de Attribute" << endl;
	#endif
    //cout<<id<<" "<<unit<<" "<<description<<endl;
    attributeId=id;
    this->unit=unit;
    this->description=description;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    