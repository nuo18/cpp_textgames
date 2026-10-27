#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <random>

struct card {
    int value;
    char suit;
}; // card

// Make the DECK
std::stack<card> initDeck() {
    std::string suits = "DSCH";
    std::stack<card> deck;

    // temp card
    card temp_card;

    for (auto s : suits) {
        for (int i = 1; i <=13; i++) {
            temp_card.suit = s;
            temp_card.value = i;

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
    std::cout << "Dealer deals a: " << deck.top().suit << deck.top().value << "\n";
    dealer_hand += deck.top().value;
    deck.pop();

    // Deals to player
    std::cout << "Player deals a: " << deck.top().suit << deck.top().value << "\n";
    player_hand += deck.top().value;
    deck.pop();

    std::cout << "\n";

    std::cout << "Player deals a: " << deck.top().suit << deck.top().value << "\n";
    player_hand += deck.top().value;
    deck.pop();

    while (!player_round_over && !game_over) {
        std::cout << "Player Total: " << player_hand << "\n";
        
        if (player_hand == 21) {
            player_won = true;
            player_round_over = true;
        }
        else if (player_hand > 21) {
            player_won = false;
            game_over = true;
            continue;
        }

        std::cout << "Press 1 to HIT and 0 to Stay!!! \n";
        std::cin >> player_choice;

        if (player_choice == 1) {
            std::cout << "Player deals a: " << deck.top().suit << deck.top().value << "\n";
            player_hand += deck.top().value;
            deck.pop();
        }
        else {player_round_over = true;}
    }

    // checking if player lost

    return 0;
}