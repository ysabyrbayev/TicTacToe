#include <iostream>
#include <string>
using namespace std;

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int r = -1;
    int c = -1;

    for (int i = 0; i < 9; i++) {
        // print game board
        cout << "   |   |  " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |  " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |  " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |  " << endl;

        // get player input
        cout << "Current Player is " << currentPlayer << endl;
        while (true) {
            cout << "Enter r c from 0-2 for row and column: ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Invalid input, try again" << endl;
            }
            else if (board[r][c] != ' ') {
                cout << "Tile if full, try again." << endl;
            }
            else {
                break;
            }
            // reset values
            r = -1;
            c = -1;
            cin.clear(); // clear error flags
            cin.ignore(10000, '\n'); // discard values
            // (skips to the next new line \n up to 10'000 char) already in input stream
        }

        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }
    
    return 0;
}