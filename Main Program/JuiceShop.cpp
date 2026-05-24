#include "JuiceBuilder.h"

// Constructor
JuiceBuilder::JuiceBuilder() {
    basePrice = 1.000;
    ingredientPrice = 0.300;

    availableIngredients.push_back("Mango");
    availableIngredients.push_back("Strawberry");
    availableIngredients.push_back("Banana");
    availableIngredients.push_back("Pineapple");
    availableIngredients.push_back("Mint");
    availableIngredients.push_back("Ice");
}

// Show ingredients the customer can choose from
void JuiceBuilder::showAvailableIngredients() const {
    cout << "Available Ingredients:" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < availableIngredients.size(); i++) {
        cout << i + 1 << ". " << availableIngredients[i]
             << " +" << ingredientPrice << " OMR" << endl;
    }

    cout << "-----------------------------" << endl;
}

// Add ingredient to custom juice
void JuiceBuilder::addIngredient(string ingredient) {
    for (int i = 0; i < availableIngredients.size(); i++) {
        if (availableIngredients[i] == ingredient) {
            selectedIngredients.push_back(ingredient);
            cout << ingredient << " added to your custom juice." << endl;
            return;
        }
    }

    cout << "Ingredient not available." << endl;
}

// Remove ingredient from custom juice
void JuiceBuilder::removeIngredient(string ingredient) {
    for (int i = 0; i < selectedIngredients.size(); i++) {
        if (selectedIngredients[i] == ingredient) {
            selectedIngredients.erase(selectedIngredients.begin() + i);
            cout << ingredient << " removed from your custom juice." << endl;
            return;
        }
    }

    cout << "Ingredient not found in your custom juice." << endl;
}

// Calculate final custom juice price
double JuiceBuilder::calculateCustomPrice() const {
    return basePrice + (selectedIngredients.size() * ingredientPrice);
}

// Create custom juice object
Juice JuiceBuilder::createCustomJuice(string customName) const {
    if (selectedIngredients.empty()) {
        throw invalid_argument("Cannot create custom juice without ingredients.");
    }

    double customPrice = calculateCustomPrice();

    cout << "Your custom juice is ready!" << endl;
    cout << "Juice Name: " << customName << endl;

    return Juice(customName, customPrice);
}

// Display selected ingredients
void JuiceBuilder::displayCustomMix() const {
    if (selectedIngredients.empty()) {
        cout << "No ingredients selected yet." << endl;
        return;
    }

    cout << "-----------------------------" << endl;
    cout << "Custom Juice Mix" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < selectedIngredients.size(); i++) {
        cout << "- " << selectedIngredients[i] << endl;
    }

    cout << "Base Price       : " << basePrice << " OMR" << endl;
    cout << "Ingredient Price : " << ingredientPrice << " OMR each" << endl;
    cout << "Total Price      : " << calculateCustomPrice() << " OMR" << endl;
    cout << "-----------------------------" << endl;
}
