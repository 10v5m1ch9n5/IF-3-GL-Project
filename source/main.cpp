#include <iostream>
#include <ctime>
#include "../interface/DataManipulation.h"
using namespace std;


int main()
{
    clock_t t1, t2;
    
    t1 = clock();
    DataManipulation * test = new DataManipulation();
    t2 = clock();
    cout<<"duree d'execution du parser de data : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<" s"<<endl;

    time_t time;
    pair<int,int> resultPair;
    float radiusResult;
    int value;
    char userInput='\0';
    string id;
    float radius, longitude, latitude;
    int nbrDay, year, day, month;
    
    cout<<"Bienvenue dans l'application AirWatcher"<<endl;
    while(userInput!='q')
    {
        cout<<endl<<"press 1 - see the list of sensors"<<endl<<"press 2 - see the list of AirCleaner"<<endl;
        cout<<"press 3 - check impact AirCleaner"<<endl<<"press 4 - check impacted radius by AirCleaner"<<endl;
        cout<<"press 5 - verify area air quality"<<endl<<"press q - quit"<<endl;
        cin >> userInput;

        switch (userInput)
        {
        case '1':
            test->listAllSensor();
            break;
        case '2':
            test->listAllAirCleaner();
            break;
        case '3':
            cout<<"enter a cleanerId"<<endl;          
            cin >> id;
            cout<<"enter a radius (example : 0.6)"<<endl;
            cin >> radius;
            t1 = clock();
            resultPair=test->checkImpactAirCleaner(id,radius);
            t2 = clock();
            switch (resultPair.first)
            {
            case -1:
                cout<<endl<<"--no sensor in this area--"<<endl;
                break;
            case -2:
                cout<<endl<<"--no measure during this time--"<<endl;
                break;
            case -3:
                cout<<endl<<"--wrong cleaner id--"<<endl;
                break;
            
            default:
                cout<<endl<<"radius : "<<radius<<" quality before : "<<test->getMapAirQuality()[resultPair.first]<<" | quality after : "<<test->getMapAirQuality()[resultPair.second]<<" | execution time : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<" s"<<endl;
                break;
            }
            break;
        case '4':
            cout<<"enter a cleanerId"<<endl;          
            cin >> id;
            t1 = clock();
            radiusResult=test->checkImpactedRadiusAirCleaner(id);
            t2 = clock();
            switch ((int)radiusResult)
            {
            case -3:
                cout<<endl<<"--wrong cleaner id--"<<endl;
                break;         
            default:
                cout<<endl<<"radius impacted : "<<radiusResult<<" | execution time : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<" s"<<endl;
                break;
            }
            break;
        case '5':
            tm date;
            cout<<"enter a longitude (example : 1.2)"<<endl;          
            cin >> longitude;
            cout<<"enter a latitude (example : 43.2)"<<endl;
            cin >> latitude;
            cout<<"enter a radius (example : 1.2)"<<endl;
            cin >> radius;
            cout<<"enter a year (example : 2019 must be > 1900)"<<endl;
            cin >> year;
            date.tm_year = year - 1900;
            cout<<"enter a month (example : 1 for january | between 1 & 12)"<<endl;
            cin >> month;
            while(month<1 || month>12)
            {
                cout<<"enter a VALID month ( > 1 && < 12 )"<<endl;
                cin >> month;
            }
            date.tm_mon= month - 1;
            cout<<"enter day of a month (example : 22)"<<endl;
            cin >> day;
            date.tm_mday = day;
            date.tm_hour=12;
            date.tm_min=0;
            date.tm_sec=0;
            date.tm_isdst = -1;
            time = mktime(&date);
            cout<<"enter nbr of day to analyse after the date you just entered ( > 1 )"<<endl;
            cin >> nbrDay;
            while(nbrDay<1)
            {
                cout<<"enter a VALID nbr of day ( > 1 )"<<endl;
                cin >> nbrDay;
            }
            t1 = clock();
            value = test->verifyAreaAirQuality(longitude,latitude,radius, time, nbrDay);
            t2 = clock();
            switch (value)
            {
            case -1:
                cout<<endl<<"--no sensor in this area--"<<endl;
                break;
            case -2:
                cout<<endl<<"--no measure during this time : "<<asctime(localtime(&time));
                break;

            default:
                cout<<"air quality : "<<test->getMapAirQuality()[value]<<" | execution time : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<" s"<<endl;
                break;
            }
            break;
        case 'q':
            break;
        default:
            cout<<"wrong input, try again with one of the number / q proposed to you"<<endl;
            break;
        }
    }
    delete(test);
    return 0;
}