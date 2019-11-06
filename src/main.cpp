#include <iostream>
#include <string>
#include "controller.h"
#include "config.h"
#include "game.h"
#include "renderer.h"

int main(int argc, char* argv[]) {
  // all game settings now are encapsulated in the Config class, with the functionalities to be loaded from a file or to be input by the user.
  Config config; // object instantiation
  
  // read setttings from file
  if (argc > 1 && std::string{argv[1]} == "-in") { 
    std::string file = std::string{argv[2]};
    config = Config(file);
  }
  
  // require user input if no file specified
  else { config = Config(1); } 


  Renderer renderer(config.GetScreenWidth(), config.GetScreenHeight(), config.GetGridWidth(), config.GetGridHeight());
  Controller controller;
  Game game(config.GetGridWidth(), config.GetGridHeight(), config.GetGameMode());
  game.Run(controller, renderer, config.GetMsPerFrame());
  std::cout << "The snake is dead. Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}