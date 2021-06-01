#include <iostream>
#include <ctime>
#include "../interface/DataManipulation.h"
using namespace std;


int main()
{
    clock_t t1, t2;

    DataManipulation * test = new DataManipulation();

    pair<int,int> result;

    cout<<endl<<"----- "<<0.5<<" -----"<<endl<<endl;

    cout<<"check impact air cleaner 0"<<endl;
    t1 = clock();
    result=test->checkImpactAirCleaner("Cleaner0",0.5);
    t2 = clock();
    cout<<"before : "<<test->getMapAirQuality()[result.first]<<" | after : "<<test->getMapAirQuality()[result.second]<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;

    cout<<"check impact air cleaner 1"<<endl;
    t1 = clock();
    result=test->checkImpactAirCleaner("Cleaner1",0.5);
    t2 = clock();
    cout<<"before : "<<test->getMapAirQuality()[result.first]<<" | after : "<<test->getMapAirQuality()[result.second]<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;

    cout<<endl<<"----- radius impacted -----"<<endl<<endl;

    cout<<"check impact air cleaner 0"<<endl;
    t1 = clock();
    cout<<"radius : "<<test->checkImpactedRadiusAirCleaner("Cleaner0")<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;
    t2 = clock();

    cout<<"check impact air cleaner 1"<<endl;
    t1 = clock();
    cout<<"radius : "<<test->checkImpactedRadiusAirCleaner("Cleaner1")<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;
    t2 = clock();

    cout<<endl<<"vérifier la qualité de l'air dans une zone"<<endl;

    tm day;
    day.tm_year=119;
    day.tm_mday=23;
    day.tm_mon=8;
    day.tm_hour=12;
    day.tm_sec=0;
    day.tm_min=0;
    time_t time =  mktime(&day);

    t1 = clock();
    int value = test->verifyAreaAirQuality(1.2,46.2,1, time);
    t2 = clock();

    cout<<"qualite : "<<test->getMapAirQuality()[value]<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;

    t1 = clock();
    value = test->verifyAreaAirQuality(1.2,46.2,1, time);
    t2 = clock();

    cout<<"qualite : "<<test->getMapAirQuality()[value]<<" duree : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<endl;
    
    delete(test);
    return 0;
}