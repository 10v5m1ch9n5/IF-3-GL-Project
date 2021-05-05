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

    
    string line;
    
    ifstream cleanersfile ("./dataset/cleaners.csv");
    string id, lat,longi,start,stop,nomEntreprise;
    int i=0;
    if (cleanersfile.is_open())
    {
            while ( getline (cleanersfile,line,';'))
            {
               
                if (line != "\n" && line !=""){
                    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
                } 
                switch ( i )
                {
                    case 0:
                        id=line;
                        break;
                    case 1:
                        lat=line;
                        break;
                    case 2:
                        longi=line;
                        break;
                    case 3:
                       start=line;
                        break;
                    case 4:
                       nomEntreprise=line;
                       cout<< id <<" cc"<<lat<< " "<< longi<<" "<<start<<" "<< nomEntreprise<< endl;
                        break;
                    default:
                        cout<<"error"<<endl;
                        break;
                }
                i=(i+1)%5;
                
            }
               cleanersfile.close();
        
     
    }else cout << "Unable to open file"; 
    
  	
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
    