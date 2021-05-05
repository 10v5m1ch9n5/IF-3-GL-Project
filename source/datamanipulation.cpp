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

void datamanipulation::verifyAreaAirQuality(string longitude, string latitude, string radius)
{
} // ----- 

void datamanipulation::verifyPointAirQuality(string longitude, string latitude)
{
} // ----- 

void datamanipulation::verifySensorAirQuality(string censorId)

{
} // ----- 

void datamanipulation::listAllSensor() const

{
} // ----- 

void datamanipulation::checkImpactAirCleaner(string airCleanerId)

{
} // ----- 

void datamanipulation::checkReliability(string userId)

{
} // ----- 


//-------------------------------------------- Constructeurs - destructeur
datamanipulation:: ~datamanipulation ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Catalogue" << endl;
	#endif
  	
}

datamanipulation::datamanipulation ()
{
	#ifdef MAP
	cout << "Appel au constructeur de Catalogue" << endl;
	#endif
    this->myListAirCleaner= new map<string, AirCleaner>;
    
    string line;
    
    ifstream cleanersfile ("../dataset/cleaners.csv");
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
                       AirCleaner myairclean= new AirCleaner (id, lat, longi,start, stop,nomEntreprise);
                       this->myListAirCleaner.insert(std::pair<string,AirCleaner>(id,myairclean));

                       new 
                       new 
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
    