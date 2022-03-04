# Code Design
1. Login/Sign up
2. Origin and destination
3. Selection of vehicle (Us recommending premium)
4. Book it (Offers - one at a time)
5. Greeting statement

Class Account -> ID, Username, Password, Age, Balance, bool first_use

Base Class Vehicle -> name_Vehicle, price/km, max_users 
Derived classes 3 - bike, auto, car -> (economy, premium)

class Travel -> origin, destination, origin_lat, orgin_long, dest_lat, dest_long, travel_distance, travel_time, api_key

Travel a("APIKEY");
a.("Origin", "Destination");


## Inputs
Origin, Destination, Choice (Bike, Auto, Economy, Premium)

## API
Inputs : Origin, Destination
Output : Distance, Duration

## Offers
Coupon codes
First rides
Loyalty privileges

## Car Prices/km
Bike : 6 Rs.
Auto : 10 Rs.
Economy : 17 Rs.
Premium : 21 Rs.

## Account System
Sign up/Login
Class Account -> Username, Password
Age
Balance

## Later
Referral system
Tracking system
Time format
Location Info