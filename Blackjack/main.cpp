#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

struct card {
    int value;
    char suit;
}; // card

// Function declaration
std::stack<card> initDeck();
std::stack<card> shuffleDeck(std::stack<card> deck);
void dealCard(std::stack<card>& deck, std::string who, int& hand);



int main () {
    std::cout << "--- Welcome to Blackjack ---\n\n";

    // Start game, init deck and shuffle
    std::stack<card> deck = initDeck();
    deck = shuffleDeck(deck);

    // variables
    int player_hand = 0;
    int dealer_hand = 0;
    bool player_round_over = false;
    bool player_won = false;
    bool game_over = false;
    int player_choice = 0;

    // Dealer deals himself
    dealCard(deck, "Dealer", dealer_hand);
    // Deals to player
    dealCard(deck, "Player", player_hand);
    std::cout << "\n";
    // Deals to player again
    dealCard(deck, "Player", player_hand);

    while (!player_round_over && !game_over) {
        std::cout << "Player Total: " << player_hand << "\n";
        
        if (player_hand == 21) {
            player_won = true;
            break;
        }
        else if (player_hand > 21) {
            game_over = true;
            break;
        }

        std::cout << "Press 1 to HIT and 0 to Stay!!! \n";
        std::cin >> player_choice;

        if (player_choice == 1) {
            dealCard(deck, "Player", player_hand);  
        }
        else {player_round_over = true;}
    }

    // checking if player lost
    if (player_won == true) {
        std::cout << "\n YOU WON!!!";
        game_over = true;
    }
    else if (game_over == true) {
        std::cout << "\n YOU LOST!!!";
    }

    // game continue
    while(!game_over) {

        dealCard(deck, "Dealer", dealer_hand);
        std::cout << "\n Dealer Total: " << dealer_hand << std::endl;

        if (dealer_hand > 21) {
            game_over = true;
            std::cout << "\nYOU WON, DEALER LOST!!!";
        }
        else if (dealer_hand < 21 && dealer_hand > player_hand) {
            game_over = true;
            std::cout << "\nYOU LOST< DEALER WON!!!";
        }
        else if (dealer_hand < 17) {
            continue;
        }
        else if (dealer_hand > 17 && dealer_hand < 21) {
            game_over = true;
            std::cout << "\nYOU WON!!! DEALER LOST";
        }
        else if (dealer_hand == 21) {
            game_over = true;
            std::cout << "\nYOU LOST!!! DEAR WON!!!";
        }
    }

    // BYE BYE
    std::cout << "\n\n BYE BYE BYE BYE, THANKS FOR PLAYING!!!" << std::endl;


    return 0;
}

// Functions
// Make the DECK
std::stack<card> initDeck() {
    std::string suits = "DSCH";
    std::stack<card> deck;

    // temp card
    card temp_card;

    for (auto s : suits) {
        for (int i = 1; i <=13; i++) {
            temp_card.suit = s;
            // Making sure King, Queen and Jack all have same value
            (i > 10) ? temp_card.value = 10 : temp_card.value = i;
            deck.push(temp_card);
        }
    }

    // return unshuffled deck
    return deck;
}

// SHuffle the Deck
std::stack<card> shuffleDeck(std::stack<card> deck) {
    // random seed
    std::random_device rd;
    // engine
    std::mt19937 g(rd());

    // temp vector
    std::vector<card> vec;

    while(!deck.empty()) {
        vec.push_back(deck.top());
        deck.pop();
    }

    // shuffle
    std::shuffle(vec.begin(), vec.end(), g);

    // putting everything back
    for (auto val : vec) {
        deck.push(val);
    }

    return deck;
}

void dealCard(std::stack<card>& deck, std::string who, int& hand) {
    std::cout << who << " deals a: " << deck.top().suit << deck.top().value << "\n";
    hand += deck.top().value;
    deck.pop();
}   