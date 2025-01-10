//Enise Aydýn
// 2200007299


// TicTacToe.h (Derived Class Header)
// TicTacToeGame.h

// Include guard to prevent multiple inclusions of the same header file
#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <string>     // String handling library for working with strings
#include <iostream>   // Input/output stream for standard I/O operations
#include "Game.h"     // Include Game class definition for inheritance

// Declaration of the TicTacToeGame class, derived from the Game class
class TicTacToeGame : public Game {
private:
    char board[3][3];  // 2D array to represent the Tic-Tac-Toe game board

public:
    // Constructors for initializing the TicTacToeGame object
    TicTacToeGame();  // Default constructor
    TicTacToeGame(const std::string& playerName);  // Constructor with player name parameter

    // Override base class functions with TicTacToeGame-specific implementations
    void start() override;  // Start the Tic-Tac-Toe game
    void end() override;    // End the Tic-Tac-Toe game
    void rules() override;  // Display rules specific to Tic-Tac-Toe
    void play(const std::string& difficulty) override;  // Play the Tic-Tac-Toe game

    // Additional Tic-Tac-Toe specific functions
    bool makeMove(char currentPlayer);  // Make a move on the Tic-Tac-Toe board
    bool isBoardFull();                  // Check if the Tic-Tac-Toe board is full
    bool checkWin(char currentPlayer);   // Check if a player has won
    void showBoard();                    // Display the current state of the Tic-Tac-Toe board

    // Destructor for cleaning up resources
    ~TicTacToeGame() override;
};

// End of the include guard
#endif // TICTACTOEGAME_H
