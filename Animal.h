#ifndef ANIMAL_H
#define ANIMAL_H
#include "Stock.h" 
using namespace std;

class Animal : public StockItem {
public:
    int hungerLevel; 
    string product;
    bool canProduce;
    Animal(string n, string d, string p) : StockItem(n,d), hungerLevel(50), product(p), canProduce(false) {}

    void feed() { hungerLevel = 0; std::cout << name << " fed.\n"; }
    
    bool isReady() override { return canProduce; }
    
    string getProduct() override { return product; }
    
    void dailyUpdate() override {
        if (hungerLevel < 100) hungerLevel += 20;
        if (!product.empty() && hungerLevel < 50) canProduce = true; else canProduce = false;
    }
    
    void displayStatus() const override {
        StockItem::displayStatus();
        cout << ", Hunger: " << hungerLevel << ", Produces: " << product
                  << (canProduce ? " (Ready)\n" : "\n");
    }



};



#endif 