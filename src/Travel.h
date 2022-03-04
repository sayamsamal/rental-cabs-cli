#ifndef _TRAVEL_H_
#define _TRAVEL_H_
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

class Travel
{
    private:
        std::string origin;
        std::string destination;
        std::string api_key;
        double travel_distance;
        int travel_time;
        double travel_amount;

    public:
        void set_distance(double dist_val);
        void set_time(int time_val);
        double get_travel_distance();
        double get_travel_time();
        std::string get_origin();
        std::string get_destination();
        Travel(std::string api_key_val);
        void calculate_trip(std::string origin_val, std::string destination_val);
};

#endif