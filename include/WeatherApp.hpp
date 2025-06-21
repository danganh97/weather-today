#ifndef WEATHER_APP_HPP
#define WEATHER_APP_HPP

#include <string>
#include "WeatherService.hpp"
#include "Speaker.hpp"

class WeatherApp {
    WeatherService service;
    Speaker speaker;

public:
    WeatherApp(const std::string& apiKey);
    void run();
};

#endif
