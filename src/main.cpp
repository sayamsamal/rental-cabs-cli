#include <iostream>
#include <iomanip>
#include <cmath>
#include "Vehicle.h"
#include "Account.h"
#include "Travel.h"
// #include "OAuth.cpp"
#include <string>
#include <cctype>

using namespace std;

static const double bike_price{6};
static const double auto_price{10};
static const double economy_price{17};
static const double premium_price{21};

std::string time_utility(int hour, int min, int sec)
{
    std::string time_return = "";
    if(hour!=0) time_return += to_string(hour) + "hr ";
    if(min!=0) time_return += to_string(min) + "min ";
    if(sec!=0) time_return += to_string(sec) + "s";
    return time_return;
}   

std::string time_format(int time_in_secs)
{
    int hour, min, sec;

    hour = time_in_secs / 3600;
    time_in_secs = time_in_secs - (hour*3600);
    min = time_in_secs / 60;
    
    time_in_secs = time_in_secs - (min*60);
    sec = time_in_secs;
    std::string time = time_utility(hour, min, sec);
    return time;
}

void welcome()
{
    cout << "*************************************************" << endl;
    cout << "\tWelcome to Rental Cabs CLI!" << endl;
    cout << "\t \t \t-- Your journey, Our ways" << endl;;
    cout << "*************************************************" << endl;
    cout << endl;
}


void get_origin_dest(std::string *origin, std::string *destination) 
{
    cout << "Enter the origin of your journey : " << endl;
    getline(cin, *origin);
    cout << "\nEnter the destination of your journey : " << endl;
    getline(cin, *destination);
}

void calculate_fare(double travel_distance)
{
    cout << "Bike (B): Rs." << ceil(travel_distance * bike_price) << endl;
    cout << "Auto (A): Rs." << ceil(travel_distance * auto_price) << endl;
    cout << "Economy (E): Rs." << ceil(travel_distance * economy_price) << endl;
    cout << "Premium (P): Rs." << ceil(travel_distance * premium_price) << endl;
}

template<typename T> void printInformation(T t, const int& width, const char separator = ' ')
{
    cout << left << setw(width) << setfill(separator) << t;
}

int main()
{
    const int labelWidth = 22, remarksWidth = 40;
    std::string origin, destination;
    char pref;
    // system("clear");
    welcome();
    get_origin_dest(&origin, &destination);
    system("clear");
    welcome();
    Travel BingApi("AtnQW7RIG8_zpEu0I-2F9x8HdaE4lgWtph02_2ns16N6_9kS2D0YahgQGo9gxVVo");
    BingApi.calculate_trip(origin, destination);
    cout << "Information for route " << origin << " to " << destination << "\n\n";
    calculate_fare(BingApi.get_travel_distance());
    cout << "\nEnter the preference of Vehicle for the journey : ";
    cin >> pref;
    pref = tolower(pref);
    Vehicle vehicle;
    switch (pref)
    {
    case 'b':
    case 'B':
        vehicle.set_info(bike_price, "Bike", 1);
        break;
    case 'a':
    case 'A':
        vehicle.set_info(auto_price, "Auto", 2);
        break;
    case 'e':
    case 'E':
        vehicle.set_info(economy_price, "Economy", 4);
        break;
    case 'p':
    case 'P':
        vehicle.set_info(premium_price, "Premium", 6);
        break;
    default:
        break;
    }
    system("clear");
    cout << "----------------\nTrip Information\n----------------\n\n";
    // cout << "Class: " << vehicle.get_name() << endl; 
    printInformation("Class:", labelWidth);
    cout << vehicle.get_name() << "\n";
    printInformation("Number of seats:", labelWidth);
    cout << vehicle.get_max_seats() << "\n";
    printInformation("Distance:", labelWidth);
    cout << BingApi.get_travel_distance() <<" km\n";
    printInformation("Estimated Time:", labelWidth);
    cout << time_format(BingApi.get_travel_time()) <<"\n";

    cout << "\n\n---\t";
    printInformation("Your ride is on its way", remarksWidth);
    cout << "---\n";

    cout << "---\t";
    printInformation("Hope you have a wonderful journey", remarksWidth);
    cout << "---\n\n\n";

    return 0;
}