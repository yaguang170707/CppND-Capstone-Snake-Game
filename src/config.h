#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

class Config {
 public:
  Config()
        :gameMode(0),
         framesPerSecond(60),
         screenWidth(640),
         screenHeight(640),
         gridWidth(32),
         gridHeight(32) {
             msPerFrame = 1000/framesPerSecond; 
             std::cout << "called" << std::endl;
             } //dummy constructor with default initialisation list
  
  Config(std::string&); //construction from file
  Config(int); //construction from user input, require passing a int to be differentiated from the default construtor
  
  // declare getter functions
  std::size_t GetGameMode() const;
  std::size_t GetFramesPerSecond() const;
  std::size_t GetMsPerFrame() const;
  std::size_t GetScreenWidth() const;
  std::size_t GetScreenHeight() const;
  std::size_t GetGridWidth() const;
  std::size_t GetGridHeight() const;

 private:
    std::size_t gameMode{0};
    std::size_t framesPerSecond{60};
    std::size_t msPerFrame{1000/framesPerSecond};
    std::size_t screenWidth{640};
    std::size_t screenHeight{640};
    std::size_t gridWidth{32};
    std::size_t gridHeight{32};

    // Print config settings summary
    void PrintConfigSummary() const;

    // global configuration selections
    static constexpr int FPSs[5] {30, 60, 120, 144, 240}; //refresh rate selections
    static constexpr double ARs[3] {1./1., 4./3., 16./9.}; //aspect ration selections
    static constexpr int s_sizes[3] {20, 25, 30}; //snake size selections
};

#endif
