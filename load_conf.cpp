#include "load_conf.hpp"
#include <fstream>
#include <map>
#include <string>

std::map<std::string, std::string> loadEnv(const std::string& filename) {
    std::map<std::string, std::string> env;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos && line[0] != '#') {
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos + 1);
            env[key] = val;
        }
    }

    return env;
}
