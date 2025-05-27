int main() {
    cout << "--- Farm Item Test ---" << endl;

    StockItem* genericItem = new StockItem("Box", "A simple wooden box");
    Animal* testAnimal = new Animal("Bessie", "A cow", "Milk");
    Plant* testPlant = new Plant("Corn Stalk", "Grows corn");

    vector<StockItem*> items;
    items.push_back(genericItem);
    items.push_back(testAnimal);
    items.push_back(testPlant);

    for (StockItem* item : items) {
        item->displayStatus();
        cout << endl;
    }

    for (StockItem* item : items) {
        delete item;
    }
    items.clear();

    cout << "Test complete." << endl;
    return 0;
}



////////////////////////





int main() {
    cout << "--- Farm Item Update Test ---" << endl;

    Animal* testAnimal = new Animal("Clucky", "A chicken", "Egg");
    Plant* testPlant = new Plant("Tomato Plant", "Grows tomatoes");

    vector<StockItem*> farmStock;
    farmStock.push_back(testAnimal);
    farmStock.push_back(testPlant);

    cout << "Initial Status:" << endl;
    for (StockItem* item : farmStock) {
        item->displayStatus();
    }

    cout << "\nAfter 1 Day Update:" << endl;
    for (StockItem* item : farmStock) {
        item->dailyUpdate();
        item->displayStatus();
    }

    cout << "\nAfter 2 Days Update:" << endl;
    for (StockItem* item : farmStock) {
        item->dailyUpdate();
        item->displayStatus();
    }

    for (StockItem* item : farmStock) {
        delete item;
    }
    farmStock.clear();

    cout << "Update test complete." << endl;
    return 0;
}

///////////////////////////////////////

int getIntInput(const string& prompt) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

///////////////////////////////


int main() {
    Inventory myInventory;
    vector<StockItem*> farmStock;
    bool running = true;

    cout << "Very Simple Farm" << endl;

    while(running) {
        cout << "\nFarm:" << endl;
        if (farmStock.empty()) {
            cout << "Empty." << endl;
        } else {
            for(size_t i = 0; i < farmStock.size(); ++i) {
                cout << i+1 << ". ";
                farmStock[i]->displayStatus();
            }
        }
        myInventory.display();

        cout << "\nMenu: 1.Add Animal 2.Add Plant 3.Next Day 4.Exit" << endl;
        int choice = getIntInput("Choice: ");

        switch(choice) {
            case 1:
                farmStock.push_back(new Animal("New Animal", "Generic", "Generic Product"));
                cout << "Animal added." << endl;
                break;
            case 2:
                farmStock.push_back(new Plant("New Plant", "Generic"));
                cout << "Plant added." << endl;
                break;
            case 3:
                cout << "A day passes..." << endl;
                for(StockItem* item : farmStock) {
                    item->dailyUpdate();
                }
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    for (StockItem* item : farmStock) {
        delete item;
    }
    farmStock.clear();
    cout << "Exiting." << endl;
    return 0;
}

//////////////////////////////////////////

 switch (choice) {
            case 1: {
                cout << "1.Chicken 2.Cow: ";
                int type = getIntInput("");
                string name = getStringInput("Name: ");
                if(type==1) farmStock.push_back(new Chicken(name, "New chicken"));
                else if(type==2) farmStock.push_back(new Cow(name, "New cow"));
                else cout << "Invalid type." << endl;
                if(type==1||type==2) actionTakenThatPassesTime = true;
                break;
            }
            case 2: {
                cout << "1.Carrot 2.Rice: ";
                int type = getIntInput("");
                string name = getStringInput("Name: ");
                if(type==1) farmStock.push_back(new Carrot(name, "New carrots"));
                else if(type==2) farmStock.push_back(new Rice(name, "New rice"));
                else cout << "Invalid type." << endl;
                if(type==1||type==2) actionTakenThatPassesTime = true;
                break;
            }
            case 3: {
                cout << "Select item by number to feed/water: ";
                int itemIdx = getIntInput("") - 1;
                if (itemIdx >= 0 && itemIdx < farmStock.size()) {
                    if (Animal* a = dynamic_cast<Animal*>(farmStock[itemIdx])) a->feed();
                    else if (Plant* p = dynamic_cast<Plant*>(farmStock[itemIdx])) p->water();
                    else cout << "Cannot feed/water this item." << endl;
                    actionTakenThatPassesTime = true;
                } else cout << "Invalid item." << endl;
                break;
            }
            case 4: {
                myInventory.display();
                if (!myInventory.items.empty()) {
                    string item = getStringInput("Item to sell: ");
                    int qty = getIntInput("Quantity: ");
                    myMarket.sell(item, qty, myInventory);
                } else cout << "Inventory empty." << endl;
                break;
            }
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }