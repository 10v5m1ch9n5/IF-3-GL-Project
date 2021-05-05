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
#include "../interface/DataManipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction 


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void DataManipulation::verifyAreaAirQuality(string longitude, string latitude, string radius)
{
} // ----- 

void DataManipulation::verifyPointAirQuality(string longitude, string latitude)
{
} // ----- 

void DataManipulation::verifySensorAirQuality(string censorId)

{
} // ----- 

void DataManipulation::listAllSensor() const

{
} // ----- 

void DataManipulation::checkImpactAirCleaner(string airCleanerId)

{
} // ----- 

void DataManipulation::checkReliability(string userId)

{
} // ----- 


//-------------------------------------------- Constructeurs - destructeur
DataManipulation:: ~DataManipulation ( )
{
	#ifdef MAP
	cout << "Appel au destructeur de Catalogue" << endl;
	#endif
  	
}

DataManipulation::DataManipulation ()
{
	#ifdef MAP
	cout << "Appel au constructeur de Catalogue" << endl;
	#endif
    
    
    string line;
    
    ifstream cleanersfile ("../dataset/cleaners.csv");
    string id, start,stop,nomEntreprise;
    float lat, longi;
    int i=0;
    if (cleanersfile.is_open())
    {
            while ( getline (cleanersfile,line,';'))
            {
               
                if (line != "\n" && line !=""){
                    //line.erase(remove(line.begin(), line.end(), '\n'), line.end());
                } 
                switch ( i )
                {
                    case 0:
                        id=line;
                        break;
                    case 1:
                        lat=stof(line);
                        break;
                    case 2:
                        longi=stof(line);
                        break;
                    case 3:
                        start=line;
                        break;
                    case 4:
                        nomEntreprise=line;
                        cout<< id <<" cc"<<lat<< " "<< longi<<" "<<start<<" "<< nomEntreprise<< endl;  
                        this->myListAirCleaner.insert(std::pair<string,AirCleaner*>(id,new AirCleaner (id, lat, longi,start, stop,nomEntreprise)));
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
    