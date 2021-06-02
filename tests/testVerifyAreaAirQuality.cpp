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
    janv01.tm_hour = 12;
    janv01.tm_mday = 1; // Premier du mois
    janv01.tm_mon = 0; // Janvier
    janv01.tm_year = 119;
    janv01.tm_yday = 0;
    janv01.tm_isdst = -1;

    DataManipulation dm;

    cout << mktime(&janv01) << endl;
    std::cout << dm.verifyAreaAirQuality(-1.0,44.0,1.0, mktime(&janv01)) << endl;
    // Capteurs dans la zone | Indice atmo moyen du 01/01/2019 = 3,7
    // Sensor0(44,-1)
    // Sensor1(44,-0.3)
    // Sensor10(44.4, -1)
    // Sensor11(44.4, -0.3)
    // Sensor20(44.8, -1)
}
