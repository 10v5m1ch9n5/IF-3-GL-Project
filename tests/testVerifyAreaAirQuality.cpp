//
// Created by lucas on 05/05/2021.
//
#include "../interface/DataManipulation.h"
#include <iostream>
#include <ctime>
int main()
{
    tm janv01;
    janv01.tm_sec = 0;
    janv01.tm_min = 0;
    janv01.tm_hour = 11;
    janv01.tm_mday = 1; // Premier du mois
    janv01.tm_mon = 0; // Janvier
    janv01.tm_year = 119;
    janv01.tm_yday = 0;
    janv01.tm_isdst = -1;

    DataManipulation dm;
    int qual;

    cout << "Vérification de la qualité de l'air aux coordonées (44;-1) dans un rayon de 1 au jour du 01/01/19" << endl;
    cout << "Indice ATMO moyen : 3,7 => Niveau de qualité de l'air 1 (Good) attendu." << endl;
    std::cout << "Niveau de qualité de l'air obtenu : " << (qual = dm.verifyAreaAirQuality(-1.0,44.0,1.0, mktime(&janv01)) ) << endl;
    if(qual == 1)
    {
        cout << "\033[32mTest validé\033[0m" << endl;
    }
    else
    {
         cout << "\033[31m échoué\033[0m" << endl;
    }
    // Capteurs dans la zone | Indice atmo moyen du 01/01/2019 = 3,7
    // Sensor0(44,-1)
    // Sensor1(44,-0.3)
    // Sensor10(44.4, -1)
    // Sensor11(44.4, -0.3)
    // Sensor20(44.8, -1)
}
