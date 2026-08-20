#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

void show() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
}

bool has_won(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

int main() {
    int move;
    char player = 'X';
    int turns = 0;

    while (turns < 9) {
        show();
        cout << "Player " << player << ", choose a number: ";
        if (!(cin >> move)) {
            if (cin.eof()) {
                cout << "\nInput ended. Goodbye!\n";
                return 0;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Enter a number from 1 to 9.\n";
            continue;
        }

        if (move < 1 || move > 9) {
            cout << "Invalid move! Choose a number from 1 to 9.\n";
            continue;
        }

        int r = (move - 1) / 3;
        int c = (move - 1) % 3;
        if (board[r][c] >= '1' && board[r][c] <= '9') {
            board[r][c] = player;
            turns++;

            if (has_won(player)) {
                show();
                cout << "Player " << player << " wins!\n";
                return 0;
            }

            player = (player == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }

    show();
    cout << "It's a draw!\n";

    return 0;
}
