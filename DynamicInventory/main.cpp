#include <iostream>

// Recreating Vector to learn about Stacks and Heaps

class MagicPouch { // acting as a Dynmaic Array
    private:
    int* loot;
    int capacity;
    int currentCount;

    public:
    MagicPouch() {
        capacity = 2;
        currentCount = 0;
        loot = new int[capacity];
    }

    ~MagicPouch() {
        delete[] loot;
        loot = nullptr;
    }

    void stashLoot(int gemValue) {
        if (currentCount == capacity) {
            // Creating a new array
            int* tempPointer = new int[capacity * 2];

            std::cout << "Pouch grows in size! Max capacity: " << capacity*2 << std::endl;

            // Copying the whole array into a new array
            for (int i = 0; i < capacity; i++) {
                tempPointer[i] = loot[i];
            }

            // Deleting old array
            delete[] loot;
            loot = tempPointer;
            capacity = capacity*2;
        }

        loot[currentCount] = gemValue;
        currentCount++;
    }

    void dropLast() {
        if (currentCount > 0) {
            loot[currentCount] = 0;
            currentCount--;
        }
    }

    void checkInventory() {
        std::cout << "Total number of items: " << currentCount << std::endl;
        std::cout << "Current Pouch capacity: " << capacity << std::endl;

        // Priting every item
        for (int i = 0; i < currentCount; i++) {
            std::cout << "Item " << i+1 << ": " << loot[i] << std::endl;
        }
    }

};



int main() {
    std::cout << "--- The Magic Loot Pouch ---\n";
    std::cout << "You venture into the dark dungeon...\n\n";

    MagicPouch myPouch;
    bool exploring = true;

    while (exploring) {
        std::cout << "\n[1] Find a Gem  [2] Drop Last Gem  [3] Check Pouch  [4] Escape Dungeon\n";
        std::cout << "What do you do? ";
        
        int choice;
        std::cin >> choice;

        // Basic input clearing if they type a letter
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            int gemValue = (rand() % 100) + 1; // Random gem value 1-100
            std::cout << "You found a ruby worth " << gemValue << " gold!\n";
            myPouch.stashLoot(gemValue);
        } 
        else if (choice == 2) {
            std::cout << "You tossed your most recently found gem into the darkness.\n";
            myPouch.dropLast();
        } 
        else if (choice == 3) {
            myPouch.checkInventory();
        } 
        else if (choice == 4) {
            std::cout << "You escaped the dungeon with your life!\n";
            exploring = false;
        }
    }
    
    return 0; 
}