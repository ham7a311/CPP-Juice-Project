#ifndef JUICEBUILDER_H
#define JUICEBUILDER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Juice.h"

using namespace std;

class JuiceBuilder {
private:
    // list of ingredients that the customer can choose from
    vector<string> availableIngredients;

    // ingredients selected by the customer
    vector<string> selectedIngredients;

    // starting price for any custom juice
    double basePrice;

    // extra price for each added ingredient
    double ingredientPrice;

public:
    // constructor
    JuiceBuilder();

    // display all available ingredients
    void showAvailableIngredients() const;

    // add ingredient to the custom juice
    void addIngredient(string ingredient);

    // remove ingredient from the custom juice
    void removeIngredient(string ingredient);

    // calculate the final price of the custom juice
    double calculateCustomPrice() const;

    // create and return the final custom juice
    Juice createCustomJuice(string customName) const;

    // display the selected ingredients and price
    void displayCustomMix() const;
};

#endif
