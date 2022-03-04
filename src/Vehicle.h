#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <string>

class Vehicle
{
    private:
        int price_per_km;
        std::string name;
        int max_seats;
    public:
        std::string get_name();
        int get_per_km();
        int get_max_seats();
        void set_info(int price_val, std::string name_val, int max_seats_val);
        // Vehicle(int price_val, std::string name_val, int max_seats_val);
};

// class Bike : public Vehicle
// {
//     public:
//         Bike(int price_val, std::string name_val = "Bike", int max_seats_val = 1);
// };

// class Auto : public Vehicle
// {
//     public:
//         Auto(int price_val, std::string name_val = "Auto", int max_seats_val = 2);
// };

// class Car : public Vehicle
// {
//     public:
//         Car(int price_val, int max_seats_val, std::string name_val = "Car");
// };

// class Economy : public Car
// {
//     public:
//         Economy(int price_val, int max_seats_val = 4, std::string name_val = "Economy Car");
// };

// class Premium : public Car
// {
//     public:
//         Premium(int price_val, int max_seats_val = 6, std::string name_val = "Premium Car");
// };

#endif 