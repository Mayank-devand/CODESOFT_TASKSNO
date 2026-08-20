#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess;

    cout << "Guess a number between 1 and 100: ";

    while (true) {
        if (!(cin >> guess)) {
            if (cin.eof()) {
                cout << "\nInput ended. Goodbye!\n";
                return 0;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a whole number: ";
            continue;
        }

        if (guess == secret) {
            cout << "Correct! You won!";
            break;
        }
        else if (guess < secret)
            cout << "Too low! Try again: ";
        else
            cout << "Too high! Try again: ";
    }

    return 0;
}