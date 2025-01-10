//Enise Aydýn
// 2200007299

// TicTacToe.cpp (Derived Class Implementation)
// TicTacToeGame.cpp

#include "TicTacToeGame.h"  // Include TicTacToeGame class definition
#include <iostream>         // Input/output stream for standard I/O operations

using namespace std;  // Added this line

// Default constructor for initializing the TicTacToeGame object
TicTacToeGame::TicTacToeGame() : Game("TicTacToe Game") {
    // Initialize the Tic-Tac-Toe board with empty spaces
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Constructor with player name parameter for initializing the TicTacToeGame object
TicTacToeGame::TicTacToeGame(const std::string& playerName) : Game(playerName) {
    // Initialize the Tic-Tac-Toe board with empty spaces
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to start the Tic-Tac-Toe game
void TicTacToeGame::start() {
    cout << "\nTIC-TAC-TOE GAME IS STARTING!!!\n" << endl;
}

// Function to end the Tic-Tac-Toe game
void TicTacToeGame::end() {
    cout << "TIC-TAC-TOE GAME ENDED!" << endl;
}

// Function to display rules specific to Tic-Tac-Toe
void TicTacToeGame::rules() {
    cout << "\nTIC-TAC-TOE RULES:\n" << endl;
    cout << "\nTwo players take turns to fill in a 3x3 grid with their symbols ('X' or 'O')."
        << "\nThe player who first gets three of their symbols in a row (horizontally, vertically, or diagonally) wins!"
        << "\nIf the entire grid is filled and no player has won, it's a draw." << endl;
    cout << "row column    row column    row column" << endl;
    cout << "1 1    1 2    1 3" << endl;
    cout << "2 1    2 2    2 3" << endl;
    cout << "3 1    3 2    3 3" << endl;
}

// Function to play the Tic-Tac-Toe game
void TicTacToeGame::play(const std::string& difficulty) {
    cout << "Playing Tic-Tac-Toe with difficulty: " << difficulty << endl;
    rules();
    start();

    char currentPlayer = 'X';
    int totalMoves = 0;

    while (!checkWin(currentPlayer) && !isBoardFull()) {
        showBoard();
        if (makeMove(currentPlayer)) {
            totalMoves++;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    if (checkWin(currentPlayer)) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }
    else {
        cout << "It's a draw!" << endl;
    }
}

// Function to make a move on the Tic-Tac-Toe board
bool TicTacToeGame::makeMove(char currentPlayer) {
    int row, col;

    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;

    // Check if the entered move is valid
    if (row < 1 || row >= 4 || col < 1 || col >= 4 || board[row][col] != ' ') {
        cout << "you entered wrong thing" << endl;
        return false; // Invalid move
    }

    board[row][col] = currentPlayer;
    return true;
}

// Function to check if the Tic-Tac-Toe board is full
bool TicTacToeGame::isBoardFull() {
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            if (board[i][j] == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full
}

// Function to check if a player has won
bool TicTacToeGame::checkWin(char currentPlayer) {
    for (int i = 1; i < 4; ++i) {
        if (board[i][1] == currentPlayer && board[i][2] == currentPlayer && board[i][3] == currentPlayer) {
            return true; // Row win
        }
    }

    for (int j = 1; j < 4; ++j) {
        if (board[1][j] == currentPlayer && board[2][j] == currentPlayer && board[3][j] == currentPlayer) {
            return true; // Column win
        }
    }

    if (board[1][1] == currentPlayer && board[2][2] == currentPlayer && board[3][3] == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }

    if (board[1][3] == currentPlayer && board[2][2] == currentPlayer && board[3][1] == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }

    return false; // No win
}

// Function to display the current state of the Tic-Tac-Toe board
void TicTacToeGame::showBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Destructor for cleaning up resources
TicTacToeGame::~TicTacToeGame() {
}
