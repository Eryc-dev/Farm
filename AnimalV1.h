#ifndef ANIMAL_H
#define ANIMAL_H
#include "Stock.h" 

class Animal : public StockItem {
public:
    int hungerLevel;
    Animal(std::string n, std::string d) : StockItem(n, d), hungerLevel(50) {}

    void feed() {
        hungerLevel = 0;
        std::cout << name << " was fed.\n"; 
    }

    bool isReady() override {
        return hungerLevel < 20; 
    }

    std::string getProduct() override {
        return "Generic Animal Product"; 
    }

    void dailyUpdate() override {
        if (hungerLevel < 100) {
            hungerLevel += 15; 
        }
    }

    void displayStatus() const override {
        StockItem::displayStatus(); 
        std::cout << ", Hunger: " << hungerLevel << "/100\n";
    }
};

#endif 