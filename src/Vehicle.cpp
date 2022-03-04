#include "Vehicle.h"

// Vehicle::Vehicle(int price_val, std::string name_val, int max_seats_val)
//     :  price_per_km {price_val}, name {name_val}, max_seats {max_seats_val}
// {

// }

// Bike::Bike(int price_val, std::string name_val, int max_seats_val)
//     : Vehicle(price_val, name_val, max_seats_val)
// {

// }

// Auto::Auto(int price_val, std::string name_val, int max_seats_val)
//     : Vehicle(price_val, name_val, max_seats_val)
// {

// }

// Car::Car(int price_val, int max_seats_val, std::string name_val)
//     : Vehicle(price_val, name_val, max_seats_val)
// {

// }

// Economy::Economy(int price_val, int max_seats_val, std::string name_val)
//     : Car(price_val, max_seats_val, name_val)
// {

// }

// Premium::Premium(int price_val, int max_seats_val, std::string name_val)
//     : Car(price_val, max_seats_val, name_val)
// {

// }

std::string Vehicle::get_name()
{
    return name;
}

 
int Vehicle::get_per_km()
{
    return price_per_km;
}


int Vehicle::get_max_seats()
{
    return max_seats;
}

void Vehicle::set_info(int price_val, std::string name_val, int max_seats_val) {
    price_per_km = price_val;
    name = name_val;
    max_seats = max_seats_val;
}
