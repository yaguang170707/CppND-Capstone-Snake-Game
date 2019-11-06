# CPPND: Capstone Snake Game 

This is my personal repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

In this project, the orignial Snake game is modified by adding the following features or fixing some original bugs:
1. The graphical settings that were originally provided in the `main.cpp` now can be user-defined by passing a `config.ini` file or by user input when start the game. An example `config.ini` file is provided below (Note that everything behind `#` is just the explanation of each entry and can be omitted);
> GameMode = 1 #0. no wall; 1. solid walls.\
> FPS = 1 #frame per second: 0. 30fps; 1. 60fps; 2. 120fps; 3. 144fps; 4. 240fps.\
> AspectRatio = 2 #0. 1:1; 1. 4:3; 2. 16:9.\
> ScreenWidth = 1200 # Screen width of the game, a recomanded size should be smaller than 0.8 * current screen horizontal resolution.\
> SnakeSize = 2 #0. small (20 pixel) 1. medium (25 pixel) 2. large (30 pixel).

2. A new game mode is added, which can be selected through the `config.ini` file or the terminal prompt. When this mode is chosen, the game will be terminated if the snake hits any of the screen boudaries, as oppose to re-appear on the other side of the screen (the original game).

3. The bug in the original game that occasionally places food beyond the scope of the screen, leading to a hanging game process, is now being fixed by slightly modifing the code.

4. The bug in the original game that freezes the game, is now being fixed by slightly modifing the code.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame` (setting the graphics interactively) or `./SnakeGame -in config.ini` (setting the graphics through a file).

## Rubric Satisfaction
The major modification is a newly defined `Config` class that encapsulates all the originally separated graphical setting variables. Three different constructors for this class are defined, setting the memeber variables via initialisation lists, from a specified file or from user input, respectively. Public member functions are defined to provide access to private member variables. Functions and Loops are used to develop this class.