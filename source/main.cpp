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
    delete(test);
    return 0;
}