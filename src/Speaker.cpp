#include "Speaker.hpp"
#include <fstream>
#include <cstdlib>

void Speaker::speak(const std::string& message) {
#ifdef _WIN32
    std::string tempFile = "speak.txt";
    std::ofstream out(tempFile);
    out << message;
    out.close();

    std::string command = "powershell -Command \"Add-Type -AssemblyName System.Speech; "
                          "$msg = Get-Content -Path './" + tempFile + "'; "
                          "$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
                          "$speak.Speak($msg);\"";
#elif __linux__
    std::string command = "espeak -v en \"" + message + "\"";
#else
    std::string command = "say \"" + message + "\"";
#endif
    system(command.c_str());
}