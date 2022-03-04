#include "Travel.h"

Travel::Travel (std::string api_key_val)
: api_key{api_key_val}
{}

double Travel::get_travel_distance()
{
    return travel_distance;
}

double Travel::get_travel_time()
{
    return travel_time;
}

std::string Travel::get_origin()
{
    return origin;
}

std::string Travel::get_destination()
{
    return destination;
}

void Travel::set_distance(double dist_val)
{
    travel_distance = dist_val;
}

void Travel::set_time(int time_val)
{
    travel_time = time_val;
}

void Travel::calculate_trip(std::string origin_val, std::string destination_val)
{
    origin = origin_val;
    destination = destination_val;
    http_client client(U("http://dev.virtualearth.net"));
    uri_builder builder(U("/REST/V1/Routes/Driving"));
    builder.append_query(U("wp.0"), origin_val);
    builder.append_query(U("wp.1"), destination_val);
    builder.append_query(U("routeAttributes"), U("routeSummariesOnly"));
    builder.append_query(U("o"), U("json"));
    builder.append_query(U("key"), api_key);

    pplx::task<void> requestJsonDistance = client.request(methods::GET, builder.to_string())
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n\n", response.status_code());
        return response.extract_json();
    })
    .then([=](json::value body)
    {
        auto array = body.at(U("resourceSets"))[0].at(U("resources"))[0];
        auto dist = array.at(U("travelDistance"));
        set_distance(array.at(U("travelDistance")).as_double());
        set_time(array.at(U("travelDurationTraffic")).as_integer());
    });

    try
    {
        requestJsonDistance.wait();
    }
    catch (const std::exception &e)
    {
        printf("Error exception:%s\n", e.what());
    }
}