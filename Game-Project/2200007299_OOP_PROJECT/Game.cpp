//Enise Aydýn
// 2200007299
// Game.cpp

#include "Game.h"  // Include Game class definition
#include <iostream> // Input/output stream for standard I/O operations

// Destructor
Game::~Game() {
    delete Player;  // Release memory allocated for the player object
}

// Function to start the game (to be implemented by derived classes)
void Game::start() {
    cout << "\nGAME IS STARTING!!!\n" << endl;
}

// Function to end the game (to be implemented by derived classes)
void Game::end() {
    cout << "end game";
}

// Function to display game rules (to be implemented by derived classes)
void Game::rules() {
    cout << "THE RULES" << endl;
    cout << endl;
}

// Function to play the game with a difficulty parameter (to be implemented by derived classes)
void Game::play(const string& difficulty) {
    cout << endl;
}

// Function to calculate and return the score based on the provided parameter
int Game::score(int& score) {
    int a = 1;
    a -= score;
    a *= 7;
    a += 100;
    cout << "Your score: " << a << endl;
    return 0;
}

