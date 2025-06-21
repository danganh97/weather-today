#include "WeatherApp.hpp"
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

WeatherApp::WeatherApp(const std::string& apiKey) : service(apiKey) {}

void WeatherApp::run() {
    std::string data = service.fetch();
    std::cout << "Raw response:\n" << data << std::endl;

    try {
        auto jsonData = json::parse(data);

        if (jsonData.contains("cod") && jsonData["cod"] != 200) {
            speaker.speak("Cannot get the weather information.");
            return;
        }

        if (jsonData.contains("weather") && jsonData.contains("main") && jsonData["weather"].is_array()) {
            std::string condition = jsonData["weather"][0]["description"];
            float temp = jsonData["main"]["temp"];

            std::ostringstream message;
            message << "Good morning, the weather today is " << temp << " degree. It's " << condition << ".";

            std::cout << message.str() << std::endl;
            speaker.speak(message.str());
        } else {
            std::cerr << "JSON data is incorrect." << std::endl;
            speaker.speak("Cannot get the weather information.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error while ingesting weather data: " << e.what() << std::endl;
        speaker.speak("Cannot get the weather information.");
    }
}