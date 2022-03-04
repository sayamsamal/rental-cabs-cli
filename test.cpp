#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <string>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main()
{
    http_client client(U("http://dev.virtualearth.net"));
    uri_builder builder(U("/REST/v1/Locations"));
    builder.append_query(U("q"), U("KIIT University"));
    builder.append_query(U("o"), U("json"));
    builder.append_query(U("key"), U("AtnQW7RIG8_zpEu0I-2F9x8HdaE4lgWtph02_2ns16N6_9kS2D0YahgQGo9gxVVo"));
    pplx::task<void> requestJson = client.request(methods::GET, builder.to_string())
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_json();
    })
    .then([=](json::value body)
    {
        auto array = body.at(U("resourceSets"))[0].at(U("resources"))[0];
        std::cout << array.at(U("point")).at(U("coordinates"))[0] << std::endl;
        std::cout << array.at(U("point")).at(U("coordinates"))[1] << std::endl;
    });

    uri_builder builder2(U("/REST/v1/Routes/DistanceMatrix"));
    builder2.append_query(U("origins"), U("27.563592, 80.675226"));
    builder2.append_query(U("destinations"), U("20.353006362915039, 85.819145202636719"));
    builder2.append_query(U("travelMode"), U("driving"));
    builder2.append_query(U("key"), U("AtnQW7RIG8_zpEu0I-2F9x8HdaE4lgWtph02_2ns16N6_9kS2D0YahgQGo9gxVVo"));

    pplx::task<void> requestJsonDistance = client.request(methods::GET, builder2.to_string())
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_json();
    })
    .then([=](json::value body)
    {
        auto array = body.at(U("resourceSets"))[0].at(U("resources"))[0];
        std::cout << "Travel Distance : " << array.at(U("results"))[0].at(U("travelDistance")) << std::endl;
        std::cout << "Travel Duration : " << array.at(U("results"))[0].at(U("travelDuration")) << std::endl;
    });

    try
    {
        requestJson.wait();
        requestJsonDistance.wait();
    }
    catch (const std::exception &e)
    {
        printf("Error exception:%s\n", e.what());
    }

    return 0;

}
