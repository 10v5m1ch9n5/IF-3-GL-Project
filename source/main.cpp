#include <iostream>
#include <ctime>
#include "../interface/DataManipulation.h"
using namespace std;


int main()
{

    DataManipulation * test = new DataManipulation();

    pair<int,int> result;

    cout<<endl<<"----- "<<0.5<<" -----"<<endl<<endl;

    cout<<"check impact air cleaner 0"<<endl;
    result=test->checkImpactAirCleaner("Cleaner0",0.5);
    cout<<"before : "<<result.first<<" | after : "<<result.second<<endl;

    cout<<"check impact air cleaner 1"<<endl;
    result=test->checkImpactAirCleaner("Cleaner1",0.5);
    cout<<"before : "<<result.first<<" | after : "<<result.second<<endl;

    cout<<endl<<"----- radius impacted -----"<<endl<<endl;

    cout<<"check impact air cleaner 0"<<endl;
    cout<<"radius : "<<test->checkImpactedRadiusAirCleaner("Cleaner0")<<endl;

    cout<<"check impact air cleaner 1"<<endl;
    cout<<"radius : "<<test->checkImpactedRadiusAirCleaner("Cleaner1")<<endl;

    cout<<endl<<"vérifier la qualité de l'air dans une zone"<<endl;

    tm day;
    day.tm_year=119;
    day.tm_mday=23;
    day.tm_mon=8;
    day.tm_hour=12;
    day.tm_sec=0;
    day.tm_min=0;
    time_t time =  mktime(&day);

    cout<<"qualite : "<<test->verifyAreaAirQuality(1.2,46.2,1, time)<<endl;

    test->listAllSensor();
    delete(test);
    return 0;
}