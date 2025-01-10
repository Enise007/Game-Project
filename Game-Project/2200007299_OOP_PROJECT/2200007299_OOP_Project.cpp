//Enise Aydýn
// 2200007299
// Main program file

#include <iostream>  // Input/output stream
#include <cstdlib>   // General utilities library
#include <ctime>     // C Standard Library time functions
#include <string>    // String handling library
#include "player.h"  // Include player class definition
#include "SynonymGame.h"  // Include SynonymGame class definition
#include "Game.h"    // Include Game class definition
#include "MovieGame.h"   // Include MovieGame class definition
#include "TicTacToeGame.h"  // Include TicTacToeGame class definition

using namespace std;

int main() {
    // Infinite loop for the game menu
    while (true) {
        cout << "Main Menu:" << endl;
        cout << "1. Find the Synonym" << endl;
        cout << "2. Guess Movie" << endl;
        cout << "3. Your Game" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        Game* game = nullptr;

        // Switch statement to create an instance of the selected game
        switch (choice) {
        case 1:
            game = new SynonymGame();
            break;
        case 2:
            game = new MovieGame();
            break;
        case 3:
            game = new TicTacToeGame();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Start and play the selected game
        game->start();
        game->play("easy");
        delete game;  // Release memory allocated for the game instance
    }

    return 0;
}
