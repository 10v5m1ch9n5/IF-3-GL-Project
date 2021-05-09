#include <iostream>

#include "../interface/DataManipulation.h"
using namespace std;

int main()
{
    DataManipulation * test = new DataManipulation();

    for(int i=0; i<3;i++)
    {
        cout<<endl<<"----- "<<0.5+i*0.05<<" -----"<<endl<<endl;
        cout<<"check impact air cleaner 0"<<endl;

        test->checkImpactAirCleaner("Cleaner0",0.5+i*0.05);

        cout<<"check impact air cleaner 1"<<endl;

        test->checkImpactAirCleaner("Cleaner1",0.5+i*0.05);
    }
    
    delete(test);
    return 0;
}