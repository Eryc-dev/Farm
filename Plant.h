#ifndef PLANT_H
#define PLANT_H
#include "Stock.h" 
using namespace std;

class Plant : public StockItem {
public:
    int growthStage; 
    float waterLevel; 
    Plant(string n, string d) : StockItem(n,d), growthStage(0), waterLevel(50.0f) {}

    void water() { waterLevel = 100.0f; cout << name << " watered.\n"; }
    
    bool isReady() override { return growthStage >= 2; }
    
    void dailyUpdate() override {
        if (growthStage < 2 && waterLevel > 30) { growthStage++; waterLevel -= 30;}
        else if (waterLevel > 0) { waterLevel -=10; }
        if(isReady() && growthStage == 2) {cout << name << " is mature!\n"; growthStage = 3; }
    }
    
    void displayStatus() const override {
        StockItem::displayStatus();
        cout << ", Stage: " << growthStage << "/2, Water: " << waterLevel << "%"
                  << (growthStage>=2 ? " (Ready)\n" : "\n");
    }
};



#endif 