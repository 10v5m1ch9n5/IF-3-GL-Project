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
#include <math.h>

//------------------------------------------------------ Include personnel
#include "../interface/DataManipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void DataManipulation::verifyAreaAirQuality(float longitude, float latitude, float radius)
{
} // -----

void DataManipulation::verifyPointAirQuality(float longitude, float latitude)
{
} // -----

void DataManipulation::findSimilarSensor(string sensorId)

{
} // -----

void DataManipulation::listAllSensor() const

{
} // -----

void DataManipulation::checkImpactAirCleaner(string airCleanerId)

{
    // le rayon est choisi arbitrairement
    double radius = 0.5 ;
    float longitude, latitude;

    AirCleaner * myAirCleaner;
    
    try
    {
        myAirCleaner = myListAirCleaner.at(airCleanerId);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    longitude = myAirCleaner->getLongitude();
    latitude = myAirCleaner->getLatitude();

    map<string, Sensor*> sensorInRadius;

    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
    {
        //cout<<pow(pow(it->second->getLatitude()-latitude,2)+pow(it->second->getLongitude()-longitude,2),0.5)<<endl;
        if( pow(pow(it->second->getLatitude()-latitude,2)+pow(it->second->getLongitude()-longitude,2),0.5) <= radius )
        {
            sensorInRadius[it->first]=it->second;
        }
    }
    int before=0;
    int after=0;
    pair<airQuality,airQuality> res;
    for (std::map<string,Sensor*>::iterator it=sensorInRadius.begin(); it!=sensorInRadius.end(); ++it)
    {
        res=it->second->getAirQuality(myAirCleaner->getTimeStampStart(), myAirCleaner->getTimeStampStop());
        before+=res.first;
        after+=res.second;
    }
    cout<<"before : "<<before<<" | after : "<<after<<endl;
} // -----

void DataManipulation::checkReliability(string userId)

{
} // -----

//-------------------------------------------- Constructeurs - destructeur
DataManipulation::~DataManipulation()
{
#ifdef MAP
    cout << "Appel au destructeur de Catalogue" << endl;
#endif
}

DataManipulation::DataManipulation()
{
#ifdef MAP
    cout << "Appel au constructeur de Catalogue" << endl;
#endif

    string line;

    // Air Cleaner

    ifstream cleanersFile("dataset/cleaners.csv");
    string  id, start, stop, nomEntreprise;
    
    float lat, longi;
    int i = 0;
    if (cleanersFile.is_open())
    {
        int a=true;
        while (getline(cleanersFile, line, ';'))
        {
            switch (i)
            {
            case 0:
                if (a==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(a==true)
                {
                    a=false;
                }
                id = line;
                break;
            case 1:
                lat = stof(line);
                break;
            case 2:
                longi = stof(line);
                break;
            case 3:
                start = line;
                break;
            case 4:
                nomEntreprise = line;
                this->myListAirCleaner.insert(std::pair<string, AirCleaner *>(id, new AirCleaner(id, lat, longi, start, stop, nomEntreprise)));
                break;
            default:
                cout << "error" << endl;
                break;
            }
            i = (i + 1) % 5;
        }
        cleanersFile.close();
    }
    else cout << "Unable to open file" << endl;

    // Sensor
    ifstream sensorsFile("dataset/sensors.csv");
    i = 0;
    
    if (sensorsFile.is_open())
    {
        int a=true;
        while (getline(sensorsFile, line, ';'))
        { 
            switch (i)
            {
            case 0:
                
                // condition qui permet de supprimer les caractères indésirables

                if (a==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(a==true)
                {
                    a=false;
                }
                id=line;
                break;
            case 1:
                lat = stof(line);
                break;
            case 2:
                longi = stof(line);
                this->myListSensors.insert(std::pair<string, Sensor *>(id, new Sensor(id, lat, longi, 0)));
                break;
            default:
                cout << "error" << endl;
                break;
            }
            i = (i + 1) % 3;
        }
        sensorsFile.close();


    }
    else cout << "Unable to open file" << endl;

    /* affichage de la list sensor

    cout<<myListSensors["Sensor1"]<<endl;

    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
    std::cout << it->first << " => " << it->second->getLatitude() << endl;
    
    cout<<myListSensors.size()<<endl;
    */

    // attribute

    string unit, attributeId, description;

    std::map<string,pair<string,string>> listAttribute;

    ifstream attributeFile("dataset/attributes.csv");
    i = 0;
    if (attributeFile.is_open())
    {
        while (getline(attributeFile, line, ';'))
        {
            int a = true;
            switch (i)
            {
            case 0:
                if (a==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(a==true)
                {
                    a=false;
                }
                attributeId = line;
                break;
            case 1:
                unit = line;
                break;
            case 2:
                description = line;
                listAttribute[id]={unit, description};
                break;
            default:
                cout << "error" << endl;
                break;
            }
            i = (i + 1) % 3;
        }
        attributeFile.close();


    }
    else cout << "Unable to open file" << endl;

    // measure

    string timeStamp;
    float value;

    //ifstream measuresFile("dataset/measurements.csv");
    ifstream measuresFile("datasetTest/measurementsTest.csv");
    i = 0;
    if (measuresFile.is_open())
    {
        while (getline(measuresFile, line, ';'))
        {
            int a = true;
            switch (i)
            {
            case 0:
                if (a==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(a==true)
                {
                    a=false;
                }
                timeStamp = line;
                break;
            case 1:
                id = line;
                break;
            case 2:
                attributeId = line;
                break;
            case 3:
                value = stof(line);
                  
                this->myListSensors[id]->addMeasure(id,timeStamp,value,attributeId,listAttribute[attributeId].first,listAttribute[attributeId].second);
                break;
            default:
                cout << "error" << endl;
                break;
            }
            i = (i + 1) % 4;
            
        }
        measuresFile.close();
        


    }
    else cout << "Unable to open file" << endl;

}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
