#ifndef PLANT_H
#define PLANT_H
#include "Stock.h"

class Plant : public StockItem {
public:
    float waterLevel; 

    Plant(std::string n, std::string d) : StockItem(n, d), waterLevel(70.0f) {} 

    void water() {
        waterLevel = 100.0f;
        std::cout << name << " was watered.\n";
    }

    bool isReady() override {
        return false; 
    }

    void dailyUpdate() override {
        if (waterLevel > 0) {
            waterLevel -= 5.0f; 
        }
    }

    void displayStatus() const override {
        StockItem::displayStatus(); 
        std::cout << ", Water: " << waterLevel << "%\n";
    }
};

#endif 