//Enise Aydýn
// 2200007299
// Game 1: Find the Synonym
// Header file for SynonymGame class

#ifndef SYNONYMGAME_H
#define SYNONYMGAME_H

#include "Game.h"  // Include Game class definition
#include <map>      // Map container definition
#include <string>   // String handling library

using namespace std;

class SynonymGame : public Game {
private:
    map<string, string> wordSynonyms;  // Map to store words and their synonyms
    int score;  // Player's score in the game
    string currentWord;  // The current word for the game round

public:
    SynonymGame();  // Default constructor
    SynonymGame(const string& playerName);  // Constructor with player name
    virtual ~SynonymGame();  // Destructor

    virtual void start() override;  // Start the game
    virtual void end() override;    // End the game
    virtual void rules() override;  // Display game rules
    virtual void play(const string& difficulty) override;  // Play the game

    void generateWord();  // Randomly select a word for the game
    void playRound();  // Play a round of the game
};

#endif // SYNONYMGAME_H



