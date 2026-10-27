#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// GUESS THE NUMBER

int main () {
    
    // Variables
    int upper_range = 0;
    int number = 0;
    int guess = 0;
    bool gameover = false;
    int tries = 0;
    int max_tries = 0;

    cout << "Welcome to GUESS THE NUMBER!!!\n";
    
    // Upper Range
    cout << "Enter the Upper Range: ";
    cin >> upper_range;

    // Max tries
    cout << "\nEnter the max amount of tries: ";
    cin >> max_tries;

    // Generating Random Number
    srand(time(0));
    cout << "\n--- Computer generating random number ---\n";
    number = (rand() % upper_range) + 1;

    while (!gameover) {
        // If max tries have been used
        if (tries >= max_tries) {
            cout << "\n GAME OVER!!! YOU LOSE!!!\n";
            cout << "The number was: " << number << "\n";

            gameover = true;
            return 0;
        }


        cout << "\nGuess the number from 1 to " << upper_range << ": ";
        cin >> guess;

        // checking if input failed
        /*if (cin.fail()) {
            cin.clear();
            cout << "\nWrong input, please enter a number: ";
        }*/

        if (guess == number) {
            cout << "Correct!!!";
            gameover = true;
        }
        else {
            cout << "Wrong!!! Try again. ";

            // High/Low implementation
            if (guess < number) {
                cout << "Go Higher!!! \n";
            }
            else {
                cout << "Go Lower!!! \n";
            }
        }
        // To implement tries system
        tries++;
    }

    cout << "\n---Game Over---\n";
    cout << "You took " << tries << " tries to guess the number.\n";

    return 0;
}