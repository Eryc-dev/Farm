#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <iostream>
using namespace std;

class StockItem { 
public:
    string name;
    string description;
    int id;
    static inline int nextId = 1; 

    StockItem(string n, string d) : name(n), description(d), id(nextId++) {}
    virtual ~StockItem() = default;
    
    virtual void displayStatus() const {
        cout << "ID: " << id << " Name: " << name; 
    }
    
    virtual void dailyUpdate() {} 
    
    virtual bool isReady() { return false; } 
    
    virtual string getProduct() { return name; } 
    
    virtual int getYield() { return 1; }
};
#endif 