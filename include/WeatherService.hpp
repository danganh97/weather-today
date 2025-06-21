#ifndef WEATHER_SERVICE_HPP
#define WEATHER_SERVICE_HPP

#include <string>

class WeatherService {
    std::string apiKey;
    std::string buffer;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

public:
    WeatherService(const std::string& key);
    std::string fetch(const std::string& city = "Da%20Nang");
};

#endif