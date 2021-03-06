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
#include <time.h>
//------------------------------------------------------ Include personnel
#include "../interface/DataManipulation.h"

using namespace std;

//--------------------------------------------------------------- Fonction

airQuality averageAirQuality(int valeur)
{
    //cout<<"valeur "<<valeur<<endl;
    switch (valeur)
    {
    case 0:
        return VeryGood;
        break;
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

int DataManipulation::verifyAreaAirQuality(float longitude, float latitude, float radius, time_t firstDay, int nbrDay)
{
    map<string, Sensor*> sensorInRadius;

    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
    {
        if( pow(pow(it->second->getLatitude()-latitude,2)+pow(it->second->getLongitude()-longitude,2),0.5) <= radius )
        {
            sensorInRadius[it->first]=it->second;
        }
    }

    int nbrMesure = sensorInRadius.size()*nbrDay;

    // dans le cas où il n'y a aucun capteur dans la zone on renvoit le code -1

    if(nbrMesure==0)
    {
        return -1;
    }

    float valueSanity;
    float valueToReturn=0;

    for(int i=0; i<nbrDay; i++)
    {
        for (std::map<string,Sensor*>::iterator it=sensorInRadius.begin(); it!=sensorInRadius.end(); ++it)
        {        
            valueSanity=it->second->getAirQuality(firstDay+i*3600*24);
            string userId=it->second->getUserID();
            if(userId.compare("\0")!=0)
            {
                myListIndividualPerson[userId]->addScore();
            }
            // Si valueSanity à la valeur -1, alors il n'y a aucune mesure pour ce capteur et pour ce temps donné 
            if(valueSanity == -1){
                nbrMesure -= 1;
            } else {
                valueToReturn+=valueSanity;
            }
        }
    }

    // si nbrMesure vaut 0 alors cela signifie qu'il n'y a aucune mesure qui correspond  
    // à ce temps dans la zone, on renvoie le code -2
    if(nbrMesure==0)
    {
        return -2;
    } else
    {
        return averageAirQuality(valueToReturn/nbrMesure);
    }
} // -----

void DataManipulation::verifyPointAirQuality(float longitude, float latitude)
{
} // -----

void DataManipulation::findSimilarSensor(string sensorId)

{
} // -----

void DataManipulation::listAllSensor() 
{
    for (std::map<string,Sensor*>::iterator it=this->myListSensors.begin(); it!=this->myListSensors.end(); ++it)
    {
        cout<<"id : "<<it->first<<" ; Latitude : "<<it->second->getLatitude()<<" ; longitude : "<<it->second->getLongitude()<<endl;
    }   
} // -----

void DataManipulation::listAllAirCleaner() 
{
    for (std::map<string,AirCleaner*>::iterator it=this->myListAirCleaner.begin(); it!=this->myListAirCleaner.end(); ++it)
    {
        cout<<"id : "<<it->first<<" ; Latitude : "<<it->second->getLatitude()<<" ; longitude : "<<it->second->getLongitude()<<endl;
    }   
} // -----

void DataManipulation::listAllIndividualPerson() 
{
    for (std::map<string,IndividualPerson*>::iterator it=this->myListIndividualPerson.begin(); it!=this->myListIndividualPerson.end(); ++it)
    {
        cout<<"id : "<<it->first<<" ; Reliable : "<<it->second->getReliability()<<" ; Score : "<<it->second->getScore()<<endl;
    }   
} // -----

float DataManipulation::checkImpactedRadiusAirCleaner(string airCleanerId)
{
    float radius=0.1;
    int valueBefore=0;
    pair<int,int> quality;
    quality = checkImpactAirCleaner(airCleanerId, radius);

    // Mauvais CLeaner id, on retourne le code -3

    if(quality.first==-3)
    {
        return -3;
    }

    while( (quality.first - quality.second)!= 0 || (quality.first==-1) )
    {
        //cout<<quality.first<<" | "<<radius<<" | "<<quality.second<<endl;

        valueBefore=quality.first;
        radius+=0.1;
        quality = checkImpactAirCleaner(airCleanerId, radius);
    }

    // condition qui permet de renvoyer 0 dans le cas où radius != 0 à cause du fait qu'il n'y
    // avait pas de capteur dans le rayon.

    if(valueBefore==-1)
    {
        return 0;
    }

    return radius;
}

pair<int,int> DataManipulation::checkImpactAirCleaner(string airCleanerId, float radius)
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
        return make_pair(-3,-3);
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

    int nbrSensor = sensorInRadius.size();
    //cout<<"sensor in radius "<<sensorInRadius.size()<<endl;

    if(nbrSensor==0)
    {
        //dans le cas où il n'y a pas de sensor dans le rayon, on renvoie -1
        return make_pair(-1,-1);
    }

    float before=0;
    float after=0;
    float value;
    for (std::map<string,Sensor*>::iterator it=sensorInRadius.begin(); it!=sensorInRadius.end(); ++it)
    {
        //cout<<"sensor id : "<<it->second->getSensorID()<<" | size list "<<it->second->getMeasure().size()<<endl;
        //cout<<endl<<"avant"<<endl<<endl;

        // -3600*24 pour avoir les analyses du dernier jour avant la début du air cleaner

        value=it->second->getAirQuality(myAirCleaner->getTimeStampStart()-3600*24);
        
        if(value==-1){
            nbrSensor -= 1;
        }else{
            before+=value;
        }

        string userId=it->second->getUserID();
        if(userId.compare("\0")!=0)
        {
            myListIndividualPerson[userId]->addScore();
        }
        
        // -3600*24 pour avoir les analyses du dernier jour avant la fin du air cleaner
        value=it->second->getAirQuality(myAirCleaner->getTimeStampStop()-3600*24);

        if(value==-1){
            nbrSensor -= 1;
        }else{
            after+=value;
        }
        
    }

    //cout<<"before : "<<before<<" | after : "<<after<<endl;

    airQuality qualityBefore, qualityAfter;


    qualityBefore = averageAirQuality(before/nbrSensor);

    qualityAfter = averageAirQuality(after/nbrSensor);

    // si nbrSensor vaut 0 alors cela signifie qu'il n'y a aucune mesure qui correspond  
    // à ce temps dans la zone, on renvoie le code -2
    if(nbrSensor==0)
    {
        return make_pair(-2,-2);
    } else
    {
        return make_pair(qualityBefore,qualityAfter);
    }
} // -----

void DataManipulation::checkReliability(string userId)

{
} // -----

//------------------------------------------------- Getter

map<int,string> DataManipulation::getMapAirQuality() const
{
		return mapAirQuality;
}

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

    for (std::map<string,IndividualPerson*>::iterator it=this->myListIndividualPerson.begin(); it!=this->myListIndividualPerson.end(); ++it)
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
    string  id, nomEntreprise;
    time_t timestampStart, timestampStop;
    tm myDate;
    myDate.tm_year = 0;
    myDate.tm_mon = 0;
    myDate.tm_mday =0;
    myDate.tm_hour = 12;
    myDate.tm_min = 0;
    myDate.tm_sec =0;
    myDate.tm_isdst = -1;
    mktime( & myDate );
    float lat, longi;
    int i = 0;
    if (cleanersFile.is_open())
    {
        while (getline(cleanersFile, line, ';'))
        {
            //remove \n from line
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            
            switch (i)
            {
            case 0:
                id = line;
                //cout<<"ID "<<id<<endl;
                break;
            case 1:
                lat = stof(line);
                break;
            case 2:
                longi = stof(line);
                break;
            case 3:
                myDate.tm_year = stoi(line.substr(0,4))-1900;
                myDate.tm_mon = stoi(line.substr(5,2))-1;
                myDate.tm_mday = stoi(line.substr(8,2));
                myDate.tm_hour = 12;
                myDate.tm_min = 0;
                myDate.tm_sec =0;
                myDate.tm_isdst = -1;
                timestampStart = mktime( & myDate );                
                break;
            case 4:
                myDate.tm_year = stoi(line.substr(0,4))-1900;
                myDate.tm_mon = stoi(line.substr(5,2))-1;
                myDate.tm_mday = stoi(line.substr(8,2)); 
                myDate.tm_hour = 12;
                myDate.tm_min = 0;
                myDate.tm_sec =0;
                myDate.tm_isdst = -1;
                timestampStop = mktime( & myDate );
                this->myListAirCleaner.insert(std::pair<string, AirCleaner *>(id, new AirCleaner(id, lat, longi, timestampStart, timestampStop)));
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
   
    cout << "Données cleaners chargées" << endl;
    // Sensor
    ifstream sensorsFile("dataset/sensors.csv");
    i = 0;
    
    if (sensorsFile.is_open())
    {
        while (getline(sensorsFile, line, ';'))
        { 
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            switch (i)
            {
            case 0:
                id=line;
                //cout<<id<<endl;
                break;
            case 1:
                lat = stof(line);
                //cout<<lat<<endl;
                break;
            case 2:
                longi = stof(line);
                //cout<<longi<<endl;
                this->myListSensors.insert(std::pair<string, Sensor *>(id, new Sensor(id, lat, longi)));
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
    
    cout << "Données sensors chargées" << endl;


    // attribute

    string unit, attributeId, description;

    std::map<string,pair<string,string>> listAttribute;

    ifstream attributeFile("dataset/attributes.csv");
    i = 0;
    if (attributeFile.is_open())
    {
        while (getline(attributeFile, line, ';'))
        {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            switch (i)
            {
            case 0:
                attributeId = line;
                break;
            case 1:
                unit = line;
                break;
            case 2:
                description = line;
                //cout << attributeId<< " "<<unit<<" " <<description << endl;
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
    
    cout << "Données Attribute chargées" << endl;
    // measure

    float value;

    ifstream measuresFile("dataset/measurements.csv");

    i = 0;

    if (measuresFile.is_open())
    {
        while (getline(measuresFile, line, ';'))
        {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            switch (i)
            {
            case 0:

                myDate.tm_year = stoi(line.substr(0,4))-1900;
                myDate.tm_mon = stoi(line.substr(5,2))-1;
                myDate.tm_mday = stoi(line.substr(8,2));
                myDate.tm_hour = 12;
                myDate.tm_min = 0;
                myDate.tm_sec =0;
                myDate.tm_isdst = -1;
                timestampStart = mktime( & myDate );
                //cout<<myDate.tm_year<<" "<<myDate.tm_mon<<" "<<myDate.tm_mday<<" "<<myDate.tm_hour<<" "<<myDate.tm_min<<" "<<myDate.tm_sec<<endl;
                
                //cout<<asctime(localtime(&timestampStart))<<endl;
                break;
            case 1:
                id = line;
                //cout<<id<<endl;
                break;
            case 2:
                attributeId = line;
                //cout<<attributeId<<endl;
                break;
            case 3:
                value = stof(line);
                //cout<<value<<endl;
                this->myListSensors[id]->addMeasure(id,timestampStart,value,attributeId,listAttribute[attributeId].first,listAttribute[attributeId].second);
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
    cout << "Données Mesures chargées" << endl;

    ifstream userFile("dataset/users.csv");

    i = 0;

    string userId, sensorId;

    if (userFile.is_open())
    {
        while (getline(userFile, line, ';'))
        {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            switch (i)
            {
            case 0:
                userId = line;

                break;
            case 1:
                sensorId=line;
                myListSensors[sensorId]->setUser(userId);
                this->myListIndividualPerson.insert(std::pair<string, IndividualPerson *>(userId, new IndividualPerson(userId)));
                break;

            default:
                cout << "error" << endl;
                break;
            }
            i = (i + 1) % 2;
            
        }
        userFile.close();
    }
    else cout << "Unable to open file" << endl;
    cout << "Données individual user chargées" << endl;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
