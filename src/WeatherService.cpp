#include "WeatherService.hpp"
#include <iostream>
#include <sstream>
#include <curl/curl.h>

WeatherService::WeatherService(const std::string& key) : apiKey(key) {}

size_t WeatherService::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total = size * nmemb;
    std::string* buf = static_cast<std::string*>(userp);
    buf->append((char*)contents, total);
    return total;
}

std::string WeatherService::fetch(const std::string& city) {
    buffer.clear();
    CURL* curl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::ostringstream url;
        url << "https://api.openweathermap.org/data/2.5/weather?q=" << city
            << "&appid=" << apiKey << "&units=metric&lang=en";

        std::cout << "Requesting URL: " << url.str() << std::endl;

        curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return buffer;
}
