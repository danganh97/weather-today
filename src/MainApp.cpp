#include <iostream>
#include "MainApp.hpp"
#include "WeatherApp.hpp"
#include "../load_conf.hpp"

int MainApp::main() {
    auto env = loadEnv(".env");
    std::string apiKey = env.count("API_KEY") ? env["API_KEY"] : "";

    if (apiKey.empty()) {
        std::cerr << "Missing API_KEY in .env file" << std::endl;
        return 1;
    }

    WeatherApp app(apiKey);
    app.run();

    return 0;
}
