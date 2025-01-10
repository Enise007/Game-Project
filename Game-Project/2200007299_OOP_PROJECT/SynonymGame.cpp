//Enise Aydýn
// 2200007299
// Implementation file for SynonymGame class

#include "SynonymGame.h"  // Include SynonymGame class definition
#include <iostream>  // Input/output stream
#include <ctime>     // C Standard Library time functions

using namespace std;

// Constructor
SynonymGame::SynonymGame() : Game("SynonymGame") {
    // Initialize wordSynonyms with pairs of words and their synonyms
    score = 0;
    wordSynonyms["beautiful"] = "pretty";
    // ... (initialize other word synonyms)
    wordSynonyms["strong"] = "powerful";
    wordSynonyms["dangerous"] = "risky";
    wordSynonyms["new"] = "fresh";
    wordSynonyms["difficult"] = "hard";
    wordSynonyms["money"] = "cash";
    wordSynonyms["big"] = "large";
    wordSynonyms["clean"] = "tidy";
    wordSynonyms["loud"] = "noisy";
    wordSynonyms["quiet"] = "silent";
    wordSynonyms["stupid"] = "foolish";
    wordSynonyms["end"] = "terminate";
    wordSynonyms["old"] = "aged";
    
}

// Destructor
SynonymGame::~SynonymGame() {
    cout << "SynonymGame game object for player '" << Player << "' is being destroyed." << endl;
}

// Start the game
void SynonymGame::start() {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed
    generateWord(); // Randomly select a word
    cout << "Starting SynonymGame game..." << endl;
    cout << endl;
    rules();
    cout << endl;
    playRound();
}

// End the game
void SynonymGame::end() {
    cout << "Game Over. Your score: " << score << endl;
}

// Display game rules
void SynonymGame::rules() {
    cout << "FindSynonym: In this game, your goal is to guess the synonym of a given word.\nYou will be presented with a word and have 5 attempts to guess its synonym correctly." << endl;
}

// Play the game
void SynonymGame::play(const string& difficulty) {
    Player = new player("Player1");  // Create a player object
    rules();
    start();
    playRound();
}

// Randomly select a word for the game
void SynonymGame::generateWord() {
    auto it = wordSynonyms.begin();
    advance(it, rand() % wordSynonyms.size());
    currentWord = it->first;
}

// Play a round of the game
void SynonymGame::playRound() {
    string guess;
    int attempts = 5;
    while (attempts > 0) {
        cout << "Guess the synonym of '" << currentWord << "': ";
        cin >> guess;
        if (guess == wordSynonyms[currentWord]) {
            cout << "Correct! The synonym of '" << currentWord << "' is '" << guess << "'." << endl;
            score = 10 * attempts; // Score based on remaining attempts
            break;
        }
        else {
            cout << "Incorrect. Try again." << endl;
            attempts--;
        }
    }
    if (attempts == 0) {
        cout << "Out of attempts. The synonym of '" << currentWord << "' is '" << wordSynonyms[currentWord] << "'." << endl;
    }
    end();
}
