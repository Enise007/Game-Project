//Enise Aydýn
// 2200007299
// MovieGame.h

#ifndef GUESSMOVIEGAME_H
#define GUESSMOVIEGAME_H

#include <iostream>  // Input/output stream for standard I/O operations
#include <cstdlib>   // General utilities library for various functionalities
#include <ctime>     // C Standard Library time functions for randomization
#include <string>    // String handling library for working with strings
#include "Game.h"    // Include Game class definition for inheritance

using namespace std;

class MovieGame : public Game {
public:
    // Constructor
    MovieGame();

    // Function to start the game
    void start() override;

    // Function to end the game and display results
    void end() override;

    // Function to display game rules
    void rules() override;

    // Function to play the movie guessing game
    void play(const std::string& difficulty) override;

private:
    string difficulty;  // Difficulty level of the game
    void initializeMovieLists();  // Initialize movie lists for different difficulties
    string getRandomMovie(const string movieList[], int size);  // Get a random movie from the specified list
    void displayHiddenMovie() const;  // Display the hidden movie with '*' for unrevealed letters
    bool isLetterInMovie(char letter);  // Check if a guessed letter is in the chosen movie and update the hidden movie
    bool isMovieGuessed();  // Check if the entire movie is guessed

    string easyMovies[4];    // Array to store easy difficulty movies
    string mediumMovies[3];  // Array to store medium difficulty movies
    string hardMovies[3];    // Array to store hard difficulty movies

    string chosenMovie;      // The selected movie for the game
    string hiddenMovie;      // The hidden representation of the movie with '*' for unrevealed letters
    int attempts;            // Number of attempts made in the game
    int score;               // Player's score in the game
};

#endif // GUESSMOVIEGAME_H

