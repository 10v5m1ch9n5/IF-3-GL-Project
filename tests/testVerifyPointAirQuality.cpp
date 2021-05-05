//
// Created by lucas on 05/05/2021.
//
#include "../interface/datamanipulation.h"
int main()
{
    Datamanipulation dm;

    // Sensor 0
    dm.verifyPointAirQuality("44","-1");
    // Reponse attendue pour le 2019-12-31 (date la plus récente)
    // O3   -> 47.75 -> ATMO 2
    // NO2  -> 73.25 -> ATMO 3
    // SO2  -> 40.75 -> ATMO 2
    // PM10 -> 45.75 -> ATMO 7
}

