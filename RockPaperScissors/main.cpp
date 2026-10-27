#include <iostream>
#include <cstdlib>
using namespace std;

// Rock paper scissors
int main() {
    // Variables
    int rounds = 0;
    int player_choice = 0;
    int player_wins = 0;
    int computer_wins = 0;
    int computer_choice = 0;
    bool gameover = false;

    cout << "--- Rock Paper Scissors ---\n";
    cout << "Welcome to my game!!! \n";

    // Game length choice
    cout << "Select best of: ";
    cin >> rounds;
    cout << "\n---\n\n";

    // Using a loop for now, should use a function here
    while(!gameover) {
        cout << "Type 1 for Rock, 2 for Paper and 3 for scissors.\n";
        cout << "Your choice: ";
        cin >> player_choice;

        computer_choice = (rand() % 3) + 1;
        cout << "\nComputer choice: " << computer_choice;
        cout << "\n";
        
        if (computer_choice == player_choice) {cout << "Draw \n";}
        else if (computer_choice == 1 && player_choice == 2) {
            cout << "You win!!!\n";
            player_wins++;
        }

        cout << computer_choice;
    }




    return 0;
}