# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)


The original Snake game has been modified in the following ways using the knowledge gained from this Nanodegree:

* The boundaries are now solid walls, rather than allowing the snake to wrap around the screen. This change was inspired by the version of Snake available to play in a web browser from Google. When the snake collides with a wall or its own body, it does not result in immediate death. Instead, the snake must turn, if possible. If no turn is possible, the game is over.

* The snake will automatically turn left by default if it collides with a wall or its own body. If a left turn is not possible, it will attempt a right turn instead. The player can always manually override the default turn. When the snake is moving rightward and makes a "left" turn, it will then start moving upwards.

* The snake's speed no longer increases with each piece of food it consumes. Instead, when the snake's length is greater than a certain threshold number of cells, its speed is reduced by 5% with each growth spurt until its length reaches another threshold cells. After this point, the speed remains constant. 

## Rubrics Fulfilled

The project demonstrates an understanding of C++ loops, functions, and input/output (I/O). This can be seen in the file "renderer.cpp" on line 93, 119, 135 in which useful new functions were created to modularize the code flow. The project also accepts user input and process it, this was achieved by making changes to the "change Direction Function" in snake.cpp on Line 224. This function changes the direction of a Snake object and restores the original direction if the new direction takes the Snake out of bounds.

The project employs object-oriented programming (OOP) techniques, as seen in the use of classes in every file except "main.cpp". These classes utilize appropriate access specifiers for their class members and encapsulate behavior, abstracting implementation details from their interfaces. Examples of using appropriate access specifiers can be found in snake.h on Line 35-48. The default data member in the starter code were public. All the data member in Snake are now private with access through getters and setters. This is also the same for behavior Encapsulation.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
