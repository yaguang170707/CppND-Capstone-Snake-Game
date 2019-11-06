#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include "config.h"

// parser function to read data from *.ini file
int lineParser(std::ifstream& cfg_file, std::string& name) {
    std::string line;
    while (getline(cfg_file, line)) {
        if(line.compare(0, name.size(), name) == 0) {
            std::istringstream buf(line);
            std::istream_iterator<std::string> beg(buf), end;
            std::vector<std::string> values(beg, end);
            return std::atoi(values[2].c_str());
        }
    }
    return 0;
}

void Config::PrintConfigSummary() const {
    std::cout << "*******************Summary*******************" << std::endl;
    std::cout << "Game Mode: " << gameMode << std::endl;
    std::cout << "Frame Per Second (Hz): " << framesPerSecond << std::endl;
    std::cout << "Frame Duration (ms): " << msPerFrame << std::endl;
    std::cout << "Screen Width (pixel): " << screenWidth << std::endl;
    std::cout << "Screen Height (pixel): " << screenHeight << std::endl;
    std::cout << "Grid Width: " << gridWidth << std::endl;
    std::cout << "Grid Height: " << gridHeight << std::endl;
    std::cout << "*********************************************" << std::endl;
}

Config::Config(std::string& config_file) {
    std::ifstream cfg_file;
    std::string name;
    cfg_file.open(config_file);
    double AR = ARs[0];
    int width = 0;
    int s_size = s_sizes[0];

    if(cfg_file){
        // read settings from file
        std::cout << "Reading settings from .ini file..." << std::endl;
        name = "GameMode";
        gameMode = lineParser(cfg_file, name);

        name = "FPS";
        framesPerSecond = FPSs[lineParser(cfg_file, name)];

        name = "AspectRatio";
        AR = ARs[lineParser(cfg_file, name)];

        name = "ScreenWidth";
        width = lineParser(cfg_file, name);

        name = "SnakeSize";
        s_size = s_sizes[lineParser(cfg_file, name)];
    }
    else{
        throw std::invalid_argument( "Invalid file name! Exit game." );
    }

    msPerFrame = 1000/framesPerSecond;

    if (width > 0 && width/s_size >= 15) { //ensure large enough screen size 
        screenWidth = int(width/s_size) * s_size;
        screenHeight = int(screenWidth/AR/s_size) * s_size;
        gridWidth = screenWidth/s_size;
        gridHeight = screenHeight/s_size;
        std::cout << "Reading completed." << std::endl;
    }
    else{
        std::cout << "Invalid screen width. Using default settings." << std::endl;
    }

    PrintConfigSummary();
}

Config::Config(int dummy) {
    double AR = ARs[0];
    int width = 0;
    int s_size = s_sizes[0];
    std::cout << "No specified settings file. Please input settings:" << std::endl;
    std::cout << "0. Use default settings;" << std::endl;
    std::cout << "1. I want to define my self." << std::endl;
    int sel;
    std::cin >> sel;

    if (sel != 0 && sel != 1) {throw std::invalid_argument("Invalid input!!!");}
    else if (sel == 0) { std::cout << "Using default settings." << std::endl; }
    else if (sel == 1) {
        std::cout << "Please select game mode:" << std::endl;
        std::cout << "   0. no surrounding walls;" << std::endl;
        std::cout << "   1. with surrounding walls (game will end if snake hits any boundaries)." << std::endl;
        std::cin >> gameMode;

        std::cout << "Please select screen refresh rate:" << std::endl;
        std::cout << "   0. 30 fps;" << std::endl;
        std::cout << "   1. 60 fps;" << std::endl;
        std::cout << "   2. 120 fps;" << std::endl;
        std::cout << "   3. 144 fps;" << std::endl;
        std::cout << "   4. 240 fps." << std::endl;
        std::cin >> sel;
        while (sel < 0 || sel > 4) {
            std::cout << "Invalid input! Please try again:" << std::endl;
            std::cin >> sel;
        }
        framesPerSecond = FPSs[sel];

        msPerFrame = 1000/framesPerSecond;

        std::cout << "Please select screen aspect ratio:" << std::endl;
        std::cout << "   0. 1:1;" << std::endl;
        std::cout << "   1. 4:3;" << std::endl;
        std::cout << "   2. 16:9." << std::endl;
        std::cin >> sel;
        while (sel < 0 || sel > 2) {
            std::cout << "Invalid input! Please try again:" << std::endl;
            std::cin >> sel;
        }
        AR = ARs[sel];

        std::cout << "Please input screen width:" << std::endl;
        std::cin >> width;
        while (width < 0) {
            std::cout << "Invalid input! Please try again:" << std::endl;
            std::cin >> width;
        }

        std::cout << "Please select snake size:" << std::endl;
        std::cout << "   0. small;" << std::endl;
        std::cout << "   1. medium;" << std::endl;
        std::cout << "   2. large;" << std::endl;
        std::cin >> sel;
        while (sel < 0 || sel > 2) {
            std::cout << "Invalid input! Please try again:" << std::endl;
            std::cin >> sel;
        }
        s_size = s_sizes[sel];

        if (width > 0 && width/s_size >= 15) { //ensure large enough screen size 
            screenWidth = int(width/s_size) * s_size;
            screenHeight = int(screenWidth/AR/s_size) * s_size;
            gridWidth = screenWidth/s_size;
            gridHeight = screenHeight/s_size;
            std::cout << "Input completed." << std::endl;
        }
        else{
            std::cout << "Invalid screen width. Using default settings." << std::endl;
        }
    }
    PrintConfigSummary();
} 

//getter functions
std::size_t Config::GetGameMode() const { return gameMode; }
std::size_t Config::GetFramesPerSecond() const { return framesPerSecond; }
std::size_t Config::GetMsPerFrame() const { return msPerFrame; }
std::size_t Config::GetScreenWidth() const { return screenWidth; }
std::size_t Config::GetScreenHeight() const { return screenHeight; }
std::size_t Config::GetGridWidth() const { return gridWidth; }
std::size_t Config::GetGridHeight() const { return gridHeight; }