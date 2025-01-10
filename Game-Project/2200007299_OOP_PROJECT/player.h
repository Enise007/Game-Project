//Enise Aydýn
// 2200007299
// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>  // Input/output stream for standard I/O operations
#include <cstdlib>   // General purpose functions, including dynamic memory management functions
#include <ctime>     // Functions to work with date and time
#include <string>    // String manipulation functions and classes

using namespace std;  // Namespace that includes the standard C++ library

class player {
private:
    string username;    // Private member variable to store the player's username
    string name_of_game; // Private member variable to store the name of the game the player is associated with
    int score;           // Private member variable to store the player's score

    friend class Game;  // Allow Game class to access private members of the player class

public:
    // Constructor that initializes the player object with a given username
    player(const string& username) : username(username), name_of_game(""), score(0) {}
};

#endif // PLAYER_H

