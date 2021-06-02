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
    cout << "Vérification de l'efficacité de Cleaner1 sur un rayon de 0,6 :" << endl;
    cout << "Indice ATMO moyen des capteurs le 31/01/19 : 3,4 => Qualité de l'air = 1 (Good)" << endl;
    cout << "Indice ATMO moyen des capteurs le 28/02/19 : 1 => Qualité de l'air = 0 (VeryGood)" << endl;
    pair<int,int> evol = dm.checkImpactAirCleaner("Cleaner1", 0.6);
    cout << "Qualité de l'air a priori : " << evol.first << endl << "Qualité de l'air a posteriori : " << evol.second << endl;
    if(evol.first == 1 && evol.second == 0)
    {
         cout << "\033[32mTest validé\033[0m" << endl;
    }
    else
    {
         cout << "\033[31mTest échoué\033[0m" << endl;
    }

    return 0;

}
