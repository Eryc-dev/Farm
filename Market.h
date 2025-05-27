#ifndef MARKET_H
#define MARKET_H
#include "Inventory.h" 
#include <string>
#include <map>
#include <iostream>
using namespace std;

// indivicual class
class Market {
public:
    //creat map 
    map<string, int> prices;
    Market() { 
        prices["Rice"] = 2; prices["Carrot"] = 1; prices["Avocado"] = 1; prices["Broccoli"] = 1;
        prices["Egg"] = 1; prices["Milk"] = 2; prices["Beef"] = 3; prices["Wool"] = 2;   
    }
    
    //sell out function
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