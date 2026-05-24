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
    vector<string> availableIngredients;
    vector<string> selectedIngredients;
    double basePrice;
    double ingredientPrice;

public:
    JuiceBuilder();

    void showAvailableIngredients() const;
    void addIngredient(string ingredient);
    void removeIngredient(string ingredient);

    double calculateCustomPrice() const;
    Juice createCustomJuice(string customName) const;

    void displayCustomMix() const;
};

#endif
