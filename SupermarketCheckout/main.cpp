#include <iostream>
#include <string>

// Customer struct
struct Customer {
    std::string name;
    int itemsInCart;
    Customer* next; // Pointer to the next customer
};

class CheckoutLane {
    private:
    Customer* front; // First customer

    public:
    CheckoutLane() {
        front = nullptr;
    }

    ~CheckoutLane() {
        // Delete everything
        while (front != nullptr) {
            Customer* temp = front;
            front = front->next;

            delete temp;
        }
    }

    void joinLine(std::string name, int items) {
        Customer* newCustomer = new Customer;
        newCustomer->name = name;
        newCustomer->itemsInCart = items;
        newCustomer->next = nullptr;

        // checking if front is empty, add new customer
        if (front == nullptr) {
            front = newCustomer;
        }
        else {
            Customer* tempPtr = front;
            while (tempPtr->next != nullptr) {
                tempPtr = tempPtr->next;
            }
            tempPtr->next = newCustomer; // adding new customer to the last customer next
        }
    }

    void serveNextCustomer () {
        if (front == nullptr) {
            std::cout << "No one in line. " << std::endl;
            return;
        }
        Customer* temp = front;
        std::cout << "Serving " << temp->name << " with " << temp->itemsInCart << " items." << std::endl;
        front = front->next;

        delete temp;
        temp = nullptr;
    }

    void frustratedCustomerLeaves() {
        if (front == nullptr) {
            return;
        }
        else if (front->next == nullptr) {
            delete front;
            front = nullptr;
            return;
        }

        Customer* tempPtr = front;
        while (tempPtr->next->next != nullptr) {
            tempPtr = tempPtr->next;
        }
        std:: cout << tempPtr->next->name << " got tired and LEFT!!!" << std::endl;

        delete tempPtr->next;
        tempPtr->next = nullptr;
    }

    // Print all the customers
    void printLine() {
        Customer* temp = front;
        int customerCount = 1;

        std::cout << "Customers in lane right now: " << std::endl;
        while (temp != nullptr) {
            std::cout << "Customer " << customerCount << ": " << temp->name << " has " << temp->itemsInCart << " items. " << std::endl;
            temp = temp->next;

            customerCount++;    
        }
    }
};

int main() {
    CheckoutLane lane1;

    std::cout << "--- Store Opens ---\n";
    lane1.joinLine("Alice", 5);
    lane1.joinLine("Bob", 12);
    lane1.joinLine("Charlie", 3);

    lane1.printLine(); // Register -> Alice(5) -> Bob(12) -> Charlie(3) -> END

    std::cout << "\n--- Cashier starts working ---\n";
    lane1.serveNextCustomer(); // Serves Alice

    lane1.printLine(); // Register -> Bob(12) -> Charlie(3) -> END

    std::cout << "\n--- The line is moving too slow ---\n";
    lane1.frustratedCustomerLeaves(); // Charlie leaves

    lane1.printLine(); // Register -> Bob(12) -> END

    std::cout << "\n--- Store Closing ---\n";
    // Destructor will automatically clean up Bob!
    return 0;
}