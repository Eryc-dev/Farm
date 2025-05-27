#ifndef SPECIFICANIMALS_H
#define SPECIFICANIMALS_H
#include "Animal.h" 
#include <string>   


//four sub class form animal class
class Sheep : public Animal {
public:
    Sheep(std::string n, std::string d) : Animal(n, d, "Wool") {}
};

class Cattle : public Animal {
public:
    Cattle(std::string n, std::string d) : Animal(n, d, "Beef") {}
};

class Cow : public Animal {
public:
    Cow(std::string n, std::string d) : Animal(n, d, "Milk") {}
};

class Chicken : public Animal {
public:
    Chicken(std::string n, std::string d) : Animal(n, d, "Egg") {}
};

#endif 