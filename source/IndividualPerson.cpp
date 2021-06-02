/*************************************************************************
                           IndividualPerson  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IndividualPerson> (fichier IndividualPerson.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "../interface/IndividualPerson.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



    
int IndividualPerson::getScore()
{
    return score;
}


bool IndividualPerson::getReliability()
{
    return reliability;
}


void IndividualPerson::addScore()
{
    score+=1;
}
    
string IndividualPerson::getId()
{
    return userId;
}

//-------------------------------------------- Constructeurs - destructeur
IndividualPerson:: ~IndividualPerson ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de IndividualPerson" << endl;
	#endif
  	
}

IndividualPerson::IndividualPerson (string id)
{
	#ifdef MAP
	cout << "Appel au constructeur de IndividualPerson" << endl;
	#endif
    userId=id;
    reliability=true;
    score=0;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    