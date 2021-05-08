#include <iostream>

#include "../interface/DataManipulation.h"
using namespace std;

int main()
{
    DataManipulation * test = new DataManipulation();
    test->checkImpactAirCleaner("Cleaner1");
    return 0;
}