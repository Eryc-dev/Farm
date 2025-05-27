#ifndef VEGETABLE_H 
#define VEGETABLE_H
#include "Plant.h"  
#include <string>  
using namespace std;

// four sub class of Plant, all inhert form Plant
class Carrot : public Plant {
public:
    Carrot(string n, string d) : Plant(n, d) {}

    string getProduct() override {
        return "Carrot"; 
    }
};

class Rice : public Plant {
public:
    Rice(string n, string d) : Plant(n, d) {}

    string getProduct() override {
        return "Rice";
    }
};

class Avocado : public Plant { 
public:
    Avocado(string n, string d) : Plant(n, d) {}

    string getProduct() override {
        return "Avocado"; 
    }
};

class Broccoli : public Plant {
public:
    Broccoli(string n, string d) : Plant(n, d) {}

    string getProduct() override {
        return "Broccoli"; 
    }
};

#endif 