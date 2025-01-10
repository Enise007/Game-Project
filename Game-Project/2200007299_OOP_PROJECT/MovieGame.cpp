//Enise Aydýn
// 2200007299
// MovieGame.cpp

#include "MovieGame.h"  // Include MovieGame class definition
#include <iostream>     // Input/output stream for standard I/O operations
#include <ctime>        // C Standard Library time functions for randomization
#include <cctype>       // Character handling functions for working with characters

using namespace std;

// Constructor
MovieGame::MovieGame() : Game("Guess the Movie"), attempts(0), score(0) {
    initializeMovieLists();  // Initialize movie lists for different difficulties
    srand(static_cast<unsigned int>(time(nullptr)));  // Initialize random seed
}

// Initialize movie lists for different difficulties
void MovieGame::initializeMovieLists() {
    easyMovies[0] = "dune";
    easyMovies[1] = "matrix";
    easyMovies[2] = "hobbit";
    easyMovies[3] = "interstellar";

    mediumMovies[0] = "star wars";
    mediumMovies[1] = "harry potter";
    mediumMovies[2] = "fight club";

    hardMovies[0] = "the lord of the rings";
    hardMovies[1] = "the hunger games";
    hardMovies[2] = "ford v ferrari";
}

// Start the movie guessing game
void MovieGame::start() {
    cout << "Select difficulty (easy, medium, hard): ";
    cin >> difficulty;
    cout << endl;

    // Choose a random movie based on the selected difficulty
    if (difficulty == "easy") {
        chosenMovie = getRandomMovie(easyMovies, 4);
    }
    else if (difficulty == "medium") {
        chosenMovie = getRandomMovie(mediumMovies, 3);
    }
    else if (difficulty == "hard") {
        chosenMovie = getRandomMovie(hardMovies, 3);
    }

    hiddenMovie = chosenMovie;
    for (char& c : hiddenMovie) {
        if (isalpha(c)) {
            c = '*';
        }
    }

    cout << "Game is starting! Can you guess the movie?" << endl;
    displayHiddenMovie();
}

// End the movie guessing game
void MovieGame::end() {
    cout << "The movie was: " << chosenMovie << endl;
    cout << "Your score: " << score << endl;
}

// Display the rules of the movie guessing game
void MovieGame::rules() {
    Game::rules();  // Inherit and display general game rules
    cout << "Guess the hidden movie name.\nYou can guess letters or the whole movie name." << endl;
    cout << endl;
}

// Play the movie guessing game
void MovieGame::play(const std::string& difficulty) {
    rules();  // Display game rules
    start();  // Start the game

    // Continue playing until the movie is guessed
    while (!isMovieGuessed()) {
        char userChoice;
        cout << "Choose an option:\n1. Guess a letter\n2. Guess the movie name\n";
        cin >> userChoice;

        if (userChoice == '1') {
            char guessedLetter;
            cout << "Enter a letter: ";
            cin >> guessedLetter;

            if (isLetterInMovie(guessedLetter)) {
                cout << "Correct guess! ";
                displayHiddenMovie();
            }
            else {
                cout << "Incorrect guess. ";
            }
        }
        else if (userChoice == '2') {
            string guessedMovie;
            cout << "Enter the movie name: ";
            cin.ignore(); // Clear the newline character from previous input
            getline(cin, guessedMovie);

            if (guessedMovie == chosenMovie) {
                cout << "Congratulations! You guessed it right." << endl;
                score += 10; // Adjust the score as needed
                break;
            }
            else {
                cout << "Incorrect guess. ";
            }
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }

        attempts++;
        displayHiddenMovie();
    }

    end();  // End the game and display results
}

// Get a random movie from the specified movie list
string MovieGame::getRandomMovie(const string movieList[], int size) {
    int randomIndex = rand() % size;
    return movieList[randomIndex];
}

// Display the hidden movie with '*' for unrevealed letters
void MovieGame::displayHiddenMovie() const {
    cout << "Hidden Movie: " << hiddenMovie << endl;
}

// Check if a guessed letter is in the chosen movie and update the hidden movie
bool MovieGame::isLetterInMovie(char letter) {
    bool letterFound = false;
    for (size_t i = 0; i < chosenMovie.size(); i++) {
        if (tolower(chosenMovie[i]) == tolower(letter)) {
            hiddenMovie[i] = chosenMovie[i];
            letterFound = true;
        }
    }
    return letterFound;
}

// Check if the entire movie is guessed
bool MovieGame::isMovieGuessed() {
    return chosenMovie == hiddenMovie;
}
