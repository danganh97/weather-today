# Weather Alarm App

A simple C++ application that fetches daily weather data using the OpenWeatherMap API and reads it aloud as an alarm at 7 AM.

## 📦 Features
- Fetch weather info from OpenWeatherMap
- Speak out weather condition using system TTS
- OOP design for better extensibility

## 🖥️ Requirements
- C++17 compatible compiler (e.g., g++)
- [libcurl](https://curl.se/libcurl/) (tested with libcurl-x64)
- [nlohmann/json](https://github.com/nlohmann/json)
- Windows PowerShell (on Windows) or `espeak`/`say` for Linux/macOS

## 🔧 Setup

1. **Install libcurl-x64**
   - Download and extract [libcurl Windows binaries](https://curl.se/windows/)
   - Add `libcurl/include` and `libcurl/lib` to your compiler flags

2. **Install nlohmann/json** header:
   - Copy `json.hpp` into your `include/` folder or install via vcpkg/conan

3. **Create `.env` file from `.env.example`**:
```env
API_KEY=your_openweathermap_api_key
```

4. **Build**:
```bash
g++ main.cpp src/*.cpp load_conf.cpp \
    -Iinclude -Icurl/include -Lcurl/lib -lcurl \
    -o weather_app.exe
```

> 🔁 Replace `curl/` path with the path to your libcurl installation.

## 🚀 Run
```bash
./weather_app.exe
```

## 📂 Project Structure
```
today-weather/
├── include/
│   ├── MainApp.hpp
│   ├── WeatherApp.hpp
│   ├── WeatherService.hpp
│   └── Speaker.hpp
├── src/
│   ├── MainApp.cpp
│   ├── WeatherApp.cpp
│   ├── WeatherService.cpp
│   └── Speaker.cpp
├── main.cpp
├── libcurl-x64.dll
├── load_conf.cpp
├── load_conf.hpp
├── .env
└── .gitignore
```


## 📜 License

MIT License © 2025 [danganh97](https://github.com/danganh97)
