#ifndef MARKET_H
#define MARKET_H
#include "Inventory.h" 
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Market {
public:
    map<string, int> prices;
    Market() { 
        prices["Rice"] = 2; prices["Carrot"] = 1;
        prices["Egg"] = 1; prices["Milk"] = 2;    
    }
    void sell(string item, int qty, Inventory& inv) {
        if (!prices.count(item)) { cout << item << " cannot be sold.\n"; return; }
        if (inv.removeItem(item, qty)) {
            int earnings = prices[item] * qty;
            inv.points += earnings;
            cout << "Sold " << qty << " " << item << " for " << earnings << " points.\n";
        } else { cout << "Not enough " << item << " to sell.\n"; }
    }
};
#endif 