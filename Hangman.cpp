#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> words = {"apple", "banana", "chocolate", "elephant", "programming", "computer", "hangman", "pizza", "jazz", "zebra"};

string getRandomWord() {
    srand(static_cast<unsigned>(time(nullptr)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

int main() {
    string secretWord = getRandomWord();
    int attempts = 6;
    string guessedWord(secretWord.length(), '_');
    char guess;

    cout << "Welcome to Hangman!" << endl;
    
    while (attempts > 0 && guessedWord != secretWord) {
        cout << "Secret Word: " << guessedWord << endl;
        cout << "Attempts Left: " << attempts << endl;
        cout << "Guess a letter: ";
        cin >> guess;

        bool correctGuess = false;

        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            cout << "Incorrect guess. Try again." << endl;
            attempts--;
        }
    }

    if (guessedWord == secretWord) {
        cout << "Congratulations! You've guessed the word: " << secretWord << endl;
    } else {
        cout << "You've run out of attempts. The word was: " << secretWord << endl;
    }

    cout << "Thanks for playing Hangman!" << endl;

    return 0;
}
