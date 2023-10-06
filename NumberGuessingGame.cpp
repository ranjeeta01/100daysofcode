#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int lowerBound = 1; // Set the lower bound of the random number range
    int upperBound = 100; // Set the upper bound of the random number range
    int secretNumber, playerGuess, attempts;
    char playAgain;

    srand(static_cast<unsigned>(time(nullptr)));

    do {
        secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
        attempts = 0;

        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I've selected a number between " << lowerBound << " and " << upperBound << ". Try to guess it!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> playerGuess;
            attempts++;

            if (playerGuess < lowerBound || playerGuess > upperBound) {
                cout << "Please enter a number between " << lowerBound << " and " << upperBound << "." << endl;
            } else if (playerGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else if (playerGuess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You've guessed the number " << secretNumber << " correctly in " << attempts << " attempts." << endl;
            }
        } while (playerGuess != secretNumber);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
