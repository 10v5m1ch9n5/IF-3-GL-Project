//
// Created by lucas on 30/05/2021.
//
#include "../interface/DataManipulation.h"
#include <iostream>

int main()
{
    DataManipulation dm;
    pair<int,int> evol = dm.checkImpactAirCleaner("1", 0.6);
    cout << evol.first << " " << evol.second << endl;

    return 0;

}
