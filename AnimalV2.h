#ifndef ANIMAL_H
#define ANIMAL_H
#include "Stock.h"
using namespace std; 

class Animal : public StockItem {
public:
    int hungerLevel;
    string product;     
    bool canProduce;   
    Animal(string n, string d, string p) : StockItem(n, d), hungerLevel(50), product(p), canProduce(false) {}

    void feed() {
        hungerLevel = 0;
        cout << name << " fed.\n";
    }

    bool isReady() override {
        return canProduce;
    }

    string getProduct() override {
        return product;
    }

    void dailyUpdate() override {
        if (hungerLevel < 100) {
            hungerLevel += 20; 
        }

        if (!product.empty() && hungerLevel < 60) { 
            canProduce = true;
        } else {
            canProduce = false;
        }
    }

    void displayStatus() const override {
        StockItem::displayStatus();
        cout << ", Hunger: " << hungerLevel << "/100" 
             << ", Produces: " << product;
        if (canProduce) {
            cout << " (Can Produce)\n"; 
        } else {
            cout << "\n";
        }
    }
};

#endif 