//
// Created by lucas on 30/05/2021.
//
#include "../interface/DataManipulation.h"
#include <iostream>

int main()
{
    DataManipulation dm;
    // Cleaner 1
    // Capteurs dans un rayon de 0.6 : sensor66;sensor67;sensor76;sensor77;sensor87
    // Mise en route : 01/02/10
    // Indice ATMO moyen des capteurs le 31/01/19 : 3,4
    // Arret du AirCleaner : 01/03/19
    // Indice ATMO moyen des capteurs le 28/02/19 : 1
    pair<int,int> evol = dm.checkImpactAirCleaner("Cleaner1", 0.6);
    cout << evol.first << " " << evol.second << endl;

    return 0;

}
