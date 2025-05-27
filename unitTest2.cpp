#include <iostream>
#include "Stock.h"    // For StockItem
#include "Plant.h"    // For the base Plant class
#include "Vegetable.h" // For Carrot, Rice, etc.

using namespace std;

void printTestHeader(const string& testName) {
    cout << "\n--- Testing: " << testName << " ---" << endl;
}

int main() {
    cout << "===== Plant Class Unit Tests =====" << endl;

    // Test 1: Carrot Creation and Growth
    printTestHeader("Carrot Creation & Growth");
    Carrot carrot1("Bunny's Fav", "An orange carrot");
    carrot1.displayStatus();
    cout << "Product: " << carrot1.getProduct() << endl;
    cout << "Is Ready (initial): " << (carrot1.isReady() ? "Yes" : "No") << endl;

    cout << "Day 1:" << endl;
    carrot1.water();
    carrot1.dailyUpdate();
    carrot1.displayStatus();

    cout << "Day 2:" << endl;
    carrot1.dailyUpdate(); // Should grow if watered enough
    carrot1.displayStatus();
    cout << "Is Ready (Day 2): " << (carrot1.isReady() ? "Yes" : "No") << endl;

    cout << "Day 3 (should be mature if logic allows):" << endl;
    carrot1.dailyUpdate();
    carrot1.displayStatus();
    cout << "Is Ready (Day 3): " << (carrot1.isReady() ? "Yes" : "No") << endl;


    // Test 2: Rice Creation and Watering
    printTestHeader("Rice Creation & Watering");
    Rice rice1("Paddy Field", "Grows white rice");
    rice1.displayStatus();
    cout << "Product: " << rice1.getProduct() << endl;
    rice1.water();
    rice1.displayStatus();


    // Test 3: Avocado (assuming it's in Vegetable.h)
    printTestHeader("Avocado Creation");
    Avocado avocado1("Guac Special", "Creamy avocado");
    avocado1.displayStatus();
    cout << "Product: " << avocado1.getProduct() << endl;


    // Test 4: Broccoli (assuming it's in Vegetable.h)
    printTestHeader("Broccoli Creation");
    Broccoli broccoli1("Green Tree", "Healthy broccoli");
    broccoli1.displayStatus();
    cout << "Product: " << broccoli1.getProduct() << endl;


    // Test 5: Polymorphism with Plant
    printTestHeader("Polymorphism with Plant");
    StockItem* gardenPlants[] = {
        new Carrot("Crunchy", "A test carrot"),
        new Rice("Mini Paddy", "A test rice field")
    };

    for (StockItem* plantPtr : gardenPlants) {
        plantPtr->displayStatus();
        Plant* actualPlant = dynamic_cast<Plant*>(plantPtr);
        if (actualPlant) {
            actualPlant->water();
            for(int i=0; i<3; ++i) actualPlant->dailyUpdate(); // Simulate growth
            cout << "Product via StockItem ptr: " << actualPlant->getProduct() << endl;
            cout << "Is Ready via StockItem ptr: " << (actualPlant->isReady() ? "Yes" : "No") << endl;
        }
        plantPtr->displayStatus(); // Show status after actions
        delete plantPtr; // Clean up
    }

    cout << "\n===== Plant Tests Finished =====" << endl;
    return 0;
}