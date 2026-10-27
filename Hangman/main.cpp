#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables
vector<string> words = {"fox", "car", "chicken", "food"};
// Would have used ASCII art to draw but aint got time
int const max_lives = 5;

int main () {
    cout << "---Welcome to Hangman---\n\n";
    
    // variables
    int lives_remaining = max_lives; // current lives
    srand(time(0));
    string word = words.at((rand() % words.size())); // getting random word from words
    bool gameover = false;
    bool player_won = false;

    // Player input
    char player_guess;
    string player_word = "";

    // intitalize player word
    for (char c : word) {
        player_word = player_word + "_";
    }

    while (!gameover) {
        cout << "The word is: ";
        for (char c : player_word) {
            cout << c << " ";
        }

        // Guessing part
        cout << "\nEnter your guess: ";
        cin >> player_guess;

        // checking if char exists in word
        bool guess_complete = false;
        for (int i = 0; i < word.size(); i++) {
            if (word.at(i) == player_guess) {
                player_word.at(i) = player_guess;
                guess_complete = true;
            }
        }
        
        if (guess_complete == false) {
            cout << "\nWrong try!!! Try again!";
            lives_remaining--;
            cout << "\nLives remaining: " << lives_remaining;
            cout << "\n";
        }

        // checking end of game
        if (player_word == word) {
            gameover = true;
            player_won = true;
        }
        else if (lives_remaining <= 0) {
            gameover = true;
            player_won = false;
        }

        cout << "\n\n";
    }

    if (player_won) {
        cout << "\nYOU WON!!!";
        cout << "\n The word was: " << word;
        cout << "\n---GAME OVER---"; 
        return 0;
    }

    cout << "\nYOU LOST!!!";
    cout << "\n The word was: " << word;
    cout << "\n---GAME OVER---"; 
    return 0;
}