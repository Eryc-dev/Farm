#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Inventory {
public:
    map<string, int> items;
    int points;
    Inventory() : points(10) {}

    void addItem(const string& itemName, int quantity = 1) {
        items[itemName] += quantity;
        cout << quantity << " " << itemName << " added to inventory.\n";
    }
   
    bool removeItem(const string& itemName, int quantity = 1) {
        if (items.count(itemName) && items[itemName] >= quantity) {
            items[itemName] -= quantity;
            if (items[itemName] == 0) items.erase(itemName);
            return true;
        }
        return false;
    }
    
    void display() const {
        cout << "\n--Inventory--\n";
        if (items.empty()) cout << "Empty.\n";
        else for (const auto& p : items) cout << p.first << ": " << p.second << "\n";
        cout << "Points: " << points << "\n-------------\n";
    }
};

#endif 