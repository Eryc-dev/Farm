#include "Animal.h"
#include "Plant.h"
#include "Stock.h"
#include "Market.h"
#include "Inventory.h"
#include "Vegetable.h"
#include "SpecificAnimal.h"
#include <iostream>
#include <vector>
#include <limits>

//  get integer input
int getIntInput(const string& prompt) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            return choice;
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

//  get string input
string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void displayFarmStatus(const vector<StockItem*>& farmStock, const Inventory& inventory) {
    cout << "\n======= Farm Status =======" << endl;
    cout << "--- Animals & Plants ---" << endl;
    if (farmStock.empty()) {
        cout << "The farm is empty." << endl;
    } else {
        for (size_t i = 0; i < farmStock.size(); ++i) {
            cout << i + 1 << ". "; // Display with 1-based index for user selection
            farmStock[i]->displayStatus();
        }
    }
    inventory.display(); // Shows inventory and points
    cout << "===================================" << endl;
}

void processDailyUpdatesAndHarvest(vector<StockItem*>& farmStock, Inventory& inventory) {
    cout << "\n[Processing daily updates and harvesting...]" << endl;
    for (StockItem* item : farmStock) {
        item->dailyUpdate();
    }

    // Harvest
    for (StockItem* item : farmStock) {
        if (item->isReady()) { // isReady for Plant is now growthStage == 2
            string productName = item->getProduct();
            int yield = item->getYield();
            cout << ">>> " << item->name << " Harvesting " << yield << " " << productName << "." << endl;
            inventory.addItem(productName, yield);

            // If it's a plant and was just harvested (was at stage 2), move it to stage 3
            if (Plant* p = dynamic_cast<Plant*>(item)) {
                if (p->growthStage == 2) {
                    p->growthStage = 3; // Mark as harvested
                }
            }
            // canProduce reset by dailyUpdate based on hunger
        }
    }
}


int main() {
    Inventory myInventory;
    Market myMarket;
    vector<StockItem*> farmStock;
    bool running = true;

    //  initial items 
    farmStock.push_back(new Chicken("aa", "initial livestock"));
    farmStock.push_back(new Rice("bb", "initial plant"));

    cout << "Welcome to Simple Farm Simulator!" << endl;

    while (running) {
        displayFarmStatus(farmStock, myInventory); // Display current status

        cout << "\nMain Menu:" << endl;
        cout << "1. Add Animal" << endl;
        cout << "2. Add Plant" << endl;
        cout << "3. Feed/Water" << endl;
        cout << "4. View Inventory" << endl;
        cout << "5. Go to Market" << endl;
        cout << "6. Exit" << endl;

        int choice = getIntInput("Enter your choice: ");


        bool actionTakenThatPassesTime = false;

        switch (choice) {
            case 1: { // Add Animal
                cout << "\nSelect animal to add:" << endl;
                cout << "1. Chicken" << endl;
                cout << "2. Cow" << endl;
                cout << "3. Sheep" << endl;
                cout << "4. Cattle" << endl;
                int animalChoice = getIntInput("Choose animal type: ");
                string name = getStringInput("Enter animal name: ");
                string desc = getStringInput("Enter animal description: ");
                if (animalChoice == 1) farmStock.push_back(new Chicken(name, desc));
                else if (animalChoice == 2) farmStock.push_back(new Cow(name, desc));
                else if (animalChoice == 3) farmStock.push_back(new Sheep(name, desc));
                else if (animalChoice == 4) farmStock.push_back(new Cattle(name, desc));
                else cout << "Invalid choice." << endl;
                if (animalChoice >=1 && animalChoice <=4) {
                    cout << name << " added to farm." << endl;
                    actionTakenThatPassesTime = true;
                }
                break;
            }
            case 2: { // Add Plant
                cout << "\nSelect plant to add:" << endl;
                cout << "1. Carrot" << endl;
                cout << "2. Rice" << endl;
                cout << "3. Avocado" << endl;
                cout << "4. Broccoli" << endl;
                int plantChoice = getIntInput("Choose plant type: ");
                string name = getStringInput("Enter plant name: ");
                string desc = getStringInput("Enter plant description: ");
                if (plantChoice == 1) farmStock.push_back(new Carrot(name, desc));
                else if (plantChoice == 2) farmStock.push_back(new Rice(name, desc));
                else if (plantChoice == 3) farmStock.push_back(new Avocado(name, desc));
                else if (plantChoice == 4) farmStock.push_back(new Broccoli(name, desc));
                else cout << "Invalid choice." << endl;
                 if (plantChoice >=1 && plantChoice <=4) {
                    cout << name << " added to farm." << endl;
                    actionTakenThatPassesTime = true;
                }
                break;
            }
            case 3: { // Feed/Water
                cout << "\n1. Feed Animal" << endl;
                cout << "2. Water Plant" << endl;
                int feedChoice = getIntInput("Choose an option: ");
                if (feedChoice == 1) {
                    if (farmStock.empty()) {cout << "No animals to feed." << endl; break;}
                    cout << "Select animal to feed by number:" << endl;
                    // List only animals
                    vector<pair<int, Animal*>> animals; // Store original index and pointer
                    for(size_t i = 0; i < farmStock.size(); ++i) {
                        if(Animal* a = dynamic_cast<Animal*>(farmStock[i])) {
                            cout << animals.size() + 1 << ". " << farmStock[i]->name << " (Hunger: " << a->hungerLevel << ")" << endl;
                            animals.push_back({(int)i, a});
                        }
                    }
                    if (animals.empty()) { cout << "No animals to feed." << endl; break; }

                     int itemNum = getIntInput("Enter number: ") -1;
                    
                    if (itemNum >= 0 && static_cast<size_t>(itemNum) < animals.size()) { 
                        animals[static_cast<size_t>(itemNum)].second->feed();            
                        actionTakenThatPassesTime = true;
                    } else {
                        cout << "Invalid animal number." << endl;
                    }
                } else if (feedChoice == 2) {
                     if (farmStock.empty()) {cout << "No plants to water." << endl; break;}
                    cout << "Select plant to water by number:" << endl;
                    // List only plants
                    vector<pair<int, Plant*>> plants;
                    for(size_t i = 0; i < farmStock.size(); ++i) {
                        if(Plant* p = dynamic_cast<Plant*>(farmStock[i])) {
                            cout << plants.size() + 1 << ". " << farmStock[i]->name << " (Water: " << p->waterLevel << "%)" << endl;
                            plants.push_back({(int)i, p});
                        }
                    }
                    if (plants.empty()) { cout << "No plants to water." << endl; break; }

                    int itemNum = getIntInput("Enter number: ") -1;
                     if (itemNum >= 0 && static_cast<size_t>(itemNum) < plants.size()) { 
                        plants[static_cast<size_t>(itemNum)].second->water();            
                        actionTakenThatPassesTime = true;
                    } else {
                        cout << "Invalid plant number." << endl;
                    }
                }
                break;
            }
            case 4: // View Inventory
                myInventory.display(); 
                break;
            case 5: { // Market
                cout << "\nWelcome to the Market!" << endl;
                myInventory.display();
                if (myInventory.items.empty()) {
                    cout << "Your inventory is empty, nothing to sell." << endl;
                    break;
                }
                string itemToSell = getStringInput("Enter name of item to sell: ");
                if (!myInventory.items.count(itemToSell) || myInventory.items[itemToSell] == 0) {
                    cout << " You don't have " << itemToSell << " in your inventory." << endl;
                    break;
                }
                int qtyToSell = getIntInput("Enter quantity to sell: ");
                if (qtyToSell <= 0) {
                    cout << "Quantity must be greater than 0." << endl;
                    break;
                }
                myMarket.sell(itemToSell, qtyToSell, myInventory);
                break;
            }

            case 6: // Exit
                running = false;
                cout << "Exiting game..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }

        if (actionTakenThatPassesTime) {
            processDailyUpdatesAndHarvest(farmStock, myInventory);
        }
        if (running) cout << "\nPress Enter to continue...";
        if (running && choice != 4 && choice != 5) { 
        }
         if (running && (choice == 4 || choice == 5 || (choice ==3 && !actionTakenThatPassesTime)) ) {
            // If no time passed, or was just viewing, still prompt to continue
        } else if(running && !actionTakenThatPassesTime && choice !=8) {
            // If an action was chosen but no actual time-passing sub-action was taken 
        }


    }

    // Cleanup
    cout << "Cleaning up resources..." << endl;
    for (StockItem* item : farmStock) {
        delete item;
    }
    farmStock.clear();

    cout << "Thanks for playing!" << endl;
    return 0;
}
