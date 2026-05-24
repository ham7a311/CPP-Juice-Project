#include "JuiceBuilder.h"

// Constructor
JuiceBuilder::JuiceBuilder() {
    extraPrice = 0.5; // Extra charge for making a custom juice
}

// Add a juice to the custom mix
void JuiceBuilder::addJuice(Juice j) {
    selectedJuices.push_back(j);
    cout << j.getJuiceName() << " added to custom juice." << endl;
}

// Remove a juice from the custom mix by name
void JuiceBuilder::removeJuice(string name) {
    for (int i = 0; i < selectedJuices.size(); i++) {
        if (selectedJuices[i].getJuiceName() == name) {
            selectedJuices.erase(selectedJuices.begin() + i);
            cout << name << " removed from custom juice." << endl;
            return;
        }
    }

    cout << "Juice not found in custom mix." << endl;
}

// Calculate the base price of the custom juice
double JuiceBuilder::calculateCustomBasePrice() const {
    double total = 0;

    for (int i = 0; i < selectedJuices.size(); i++) {
        total += selectedJuices[i].getBasePrice();
    }

    return total + extraPrice;
}

// Create and return the final custom juice
Juice JuiceBuilder::createCustomJuice(string customName) const {
    if (selectedJuices.empty()) {
        throw invalid_argument("Cannot create custom juice without selected juices.");
    }

    double customPrice = calculateCustomBasePrice();

    return Juice(customName, customPrice);
}

// Display the selected juices in the mix
void JuiceBuilder::displayCustomMix() const {
    if (selectedJuices.empty()) {
        cout << "No juices selected yet." << endl;
        return;
    }

    cout << "Custom Juice Mix:" << endl;

    for (int i = 0; i < selectedJuices.size(); i++) {
        cout << "- " << selectedJuices[i].getJuiceName() << endl;
    }

    cout << "Custom Base Price: " << calculateCustomBasePrice() << endl;
}