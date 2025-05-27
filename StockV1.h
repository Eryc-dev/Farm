#ifndef STOCKV1_H
#define STOCKV1_H
#include <string>
#include <iostream>
using namespace std

///////////////////////////////////////
class StockItem {
public:
    string name;
    string description;
    
    StockItem(string n, string d) : name(n), description(d) {}

    void displayStatus() const {
        cout << "Name: " << name << ", Desc: " << description << endl;
    }


    void dailyUpdate() { }
    bool isReady() { return false; }
    string getProduct() { return name;  }
};

#endif 