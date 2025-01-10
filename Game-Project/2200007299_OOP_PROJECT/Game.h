//Enise Aydýn
// 2200007299
// Game.h

#ifndef GAME_H
#define GAME_H

#include <iostream>  // Input/output stream for standard I/O operations
#include <cstdlib>   // General utilities library for various functionalities
#include <ctime>     // C Standard Library time functions for randomization
#include <string>    // String handling library for working with strings
#include "player.h"  // Include player class definition for player-related functionality

using namespace std;

class Game {
protected:
    string name;    // Name of the game
    player* Player; // Pointer to a player object
    int attempts;   // Number of attempts made in the game

public:
    // Constructor with a name parameter
    Game(const string& name) : name(name), Player(nullptr), attempts(0) {}

    // Pure virtual function to start the game, to be implemented by derived classes
    virtual void start() = 0;

    // Pure virtual function to end the game, to be implemented by derived classes
    virtual void end() = 0;

    // Pure virtual function to display game rules, to be implemented by derived classes
    virtual void rules() = 0;

    // Pure virtual function to play the game, with a difficulty parameter, to be implemented by derived classes
    virtual void play(const string& difficulty) = 0;

    // Function to calculate and return the score based on the provided parameter
    int score(int& score);

    // Destructor to release memory allocated for the player object
    virtual ~Game();
};

#endif // GAME_H

