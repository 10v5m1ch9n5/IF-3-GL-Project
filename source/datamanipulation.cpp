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
    int longitude, latitude;

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

    ifstream cleanersFile("../dataset/test.txt");
    string id, start, stop, nomEntreprise;
    float lat, longi;
    int i = 0;
    if (cleanersFile.is_open())
    {
        while (getline(cleanersFile, line, ';'))
        {

            if (line != "\n" && line != "")
            {
                //line.erase(remove(line.begin(), line.end(), '\n'), line.end());
            }
            switch (i)
            {
            case 0:
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
                cout << id << " cc" << lat << " " << longi << " " << start << " " << nomEntreprise << endl;
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
    else
        cout << "Unable to open file" << endl;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
