#ifndef JUICEBUILDER_H
#define JUICEBUILDER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Juice.h"
using namespace std;

// This class allows the customer to build a custom juice mix.
class JuiceBuilder {
private:
    vector<Juice> selectedJuices;
    double extraPrice;

public:
    // Constructor
    JuiceBuilder();

    // Add a juice to the custom mix
    void addJuice(Juice j);

    // Remove a juice from the custom mix by name
    void removeJuice(string name);

    // Calculate the base price of the custom juice
    double calculateCustomBasePrice() const;

    // Create and return the final custom juice
    Juice createCustomJuice(string customName) const;

    // Display the selected juices in the mix
    void displayCustomMix() const;
};

#endif