#include <iostream>
#include <vector>

void displayBoard(const std::vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        std::cout << board[i] << ((i % 3 == 2) ? "\n" : " | ");
        if (i % 3 == 2 && i < 8) std::cout << "---------\n";
    }
}

bool checkWin(const std::vector<char>& board, char player) {
    int winStates[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
    for (auto& state : winStates) {
        if (board[state[0]] == player && board[state[1]] == player && board[state[2]] == player) return true;
    }
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) if (cell == ' ') return false;
    return true;
}

void playGame() {
    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;
        move--;

        if (move < 0 || move >= 9 || board[move] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

