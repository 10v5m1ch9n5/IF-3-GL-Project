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
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "../interface/DataManipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction

airQuality averageAirQuality(int valeur)
{
    //cout<<"valeur "<<valeur<<endl;
    switch (valeur)
    {
    case 1:
        return VeryGood;
        break;
    case 2:
        return VeryGood;
        break;
    case 3:
        return Good;
        break;
    case 4:
        return Good;
        break;
    case 5:
        return Average;
        break;
    case 6:
        return Poor;
        break;
    case 7:
        return Poor;
        break;
    case 8:
        return Bad;
        break;
    case 9:
        return Bad;
        break;
    case 10:
        return VeryBad;
        break;
    default:
        return Average; 
        break;
    }
}


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

void DataManipulation::checkImpactAirCleaner(string airCleanerId, float radius)

{
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

    //cout<<longitude<<" | "<<latitude<<endl;

    map<string, Sensor*> sensorInRadius;

    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
    {
        //cout<<pow(pow(it->second->getLatitude()-latitude,2)+pow(it->second->getLongitude()-longitude,2),0.5)<<endl;
        if( pow(pow(it->second->getLatitude()-latitude,2)+pow(it->second->getLongitude()-longitude,2),0.5) <= radius )
        {
            sensorInRadius[it->first]=it->second;
        }
    }

    cout<<"sensor in radius "<<sensorInRadius.size()<<endl;

    float before=0;
    float after=0;
    pair<float,float> res;
    for (std::map<string,Sensor*>::iterator it=sensorInRadius.begin(); it!=sensorInRadius.end(); ++it)
    {
        cout<<"sensor id : "<<it->second->getSensorID()<<" | size list "<<it->second->getMeasure().size()<<endl;
        res=it->second->getAirQuality(myAirCleaner->getTimeStampStart(), myAirCleaner->getTimeStampStop());
        before+=res.first;
        after+=res.second;
    }

    cout<<"before : "<<before<<" | after : "<<after<<endl;

    if(sensorInRadius.size()!=0)
    {
        airQuality qualityBefore = averageAirQuality(before/sensorInRadius.size());

        airQuality qualityAfter = averageAirQuality(after/sensorInRadius.size());
        cout<<"Qualite --plus c'est proche de 0 plus c'est bon--"<<endl<<"before : "<<qualityBefore<<" | after : "<<qualityAfter<<endl;
    }

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

    //delete sensor
    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
        delete(it->second);

    //delete airCleaner
    for (std::map<string,AirCleaner*>::iterator it=this->myListAirCleaner.begin(); it!=this->myListAirCleaner.end(); ++it)
        delete(it->second);
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
        while (getline(cleanersFile, line, ';'))
        {
            //remove \n from line
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            //cout<<"LINE "<<line<<endl;
            switch (i)
            {
            case 0:
                id = line;
                //cout<<"ID "<<id<<endl;
                break;
            case 1:
                lat = stof(line);
                //cout<<"lat "<<lat<<endl;
                break;
            case 2:
                longi = stof(line);
                //cout<<"long "<<longi<<endl;
                break;
            case 3:
                start = line;
                //cout<<"start "<<start<<endl;
                break;
            case 4:
                stop = line;
                //cout<<"stop "<<stop<<endl;
                this->myListAirCleaner.insert(std::pair<string, AirCleaner *>(id, new AirCleaner(id, lat, longi, start, stop)));
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
   
    cout << "Données cleaners chargée" << endl;
    // Sensor
    ifstream sensorsFile("dataset/sensors.csv");
    i = 0;
    
    if (sensorsFile.is_open())
    {
        int premiereLigne=true;
        while (getline(sensorsFile, line, ';'))
        { 
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            switch (i)
            {
            case 0:
                id=line;
                cout<<id<<endl;
                break;
            case 1:
                lat = stof(line);
                cout<<lat<<endl;
                break;
            case 2:
                longi = stof(line);
                cout<<longi<<endl;
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
    
    cout << "Données cleaners chargée" << endl;
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
        int premiereLigne = true;
        while (getline(attributeFile, line, ';'))
        {
            
            switch (i)
            {
            case 0:
                if (premiereLigne==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(premiereLigne==true)
                {
                    premiereLigne=false;
                }
                attributeId = line;
                break;
            case 1:
                unit = line;
                break;
            case 2:
                description = line;
                listAttribute[attributeId]=pair<string,string>(unit, description);
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

    ifstream measuresFile("dataset/measurements.csv");
    //ifstream measuresFile("datasetTest/measurementsTest.csv");
    i = 0;
    if (measuresFile.is_open())
    {
        int premiereLigne = true;
        while (getline(measuresFile, line, ';'))
        {
            
            switch (i)
            {
            case 0:
                if (premiereLigne==false && line != "\n" && line != "")
                {
                    line.erase(0, 2);
                }
                if(premiereLigne==true)
                {
                    premiereLigne=false;
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
