#include <iostream>
#include "Stock.h"        // For StockItem
#include "Animal.h"       // For the base Animal class
#include "SpecificAnimal.h" // For Chicken, Cow, Sheep, Cattle

using namespace std;

void printTestHeader(const string& testName) {
    cout << "\n--- Testing: " << testName << " ---" << endl;
}

int main() {
    cout << "===== Animal Class Unit Tests =====" << endl;

    // Test 1: Chicken Creation and Basic Methods
    printTestHeader("Chicken Creation & Basic Methods");
    Chicken chicken1("Clucky", "A happy hen");
    chicken1.displayStatus();
    cout << "Product: " << chicken1.getProduct() << endl;
    cout << "Is Ready (initial): " << (chicken1.isReady() ? "Yes" : "No") << endl;
    chicken1.feed();
    chicken1.dailyUpdate(); // Hunger will increase, might become ready
    cout << "Is Ready (after feed & update): " << (chicken1.isReady() ? "Yes" : "No") << endl;
    chicken1.displayStatus();

    // Test 2: Cow Creation and Basic Methods
    printTestHeader("Cow Creation & Basic Methods");
    Cow cow1("Daisy", "A gentle giant");
    cow1.displayStatus();
    cout << "Product: " << cow1.getProduct() << endl;
    for (int i = 0; i < 3; ++i) { // Simulate a few days
        cow1.dailyUpdate();
    }
    cow1.feed(); // Feed after it gets hungry
    cow1.dailyUpdate(); // Check if it can produce
    cow1.displayStatus();

    // Test 3: Sheep Creation
    printTestHeader("Sheep Creation");
    Sheep sheep1("Wooly", "A fluffy sheep");
    sheep1.displayStatus();
    cout << "Product: " << sheep1.getProduct() << endl;


    // Test 4: Cattle Creation
    printTestHeader("Cattle Creation");
    Cattle cattle1("Angus", "A beefy cattle");
    cattle1.displayStatus();
    cout << "Product: " << cattle1.getProduct() << endl;

    // Test 5: Polymorphism with StockItem pointers
    printTestHeader("Polymorphism with Animal");
    StockItem* farmAnimals[] = {
        new Chicken("Henrietta", "Another hen"),
        new Cow("Bess", "Another cow")
    };

    for (StockItem* animalPtr : farmAnimals) {
        animalPtr->displayStatus();
        Animal* actualAnimal = dynamic_cast<Animal*>(animalPtr);
        if (actualAnimal) {
            actualAnimal->feed();
            actualAnimal->dailyUpdate();
            cout << "Product via StockItem ptr: " << actualAnimal->getProduct() << endl;
            cout << "Is Ready via StockItem ptr: " << (actualAnimal->isReady() ? "Yes" : "No") << endl;
        }
        animalPtr->displayStatus(); // Show status after actions
        delete animalPtr; // Clean up
    }


    cout << "\n===== Animal Tests Finished =====" << endl;
    return 0;
}