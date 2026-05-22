#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Customer : public Person {
private:
    int customerID;
    inline static int counter = 1;

public:
    // Constructor
    Customer(string n, string num = "00000000");

    // Getter
    int getCustomerID() const;

    // Place order
    void placeOrder() const;

    // Override display function from Person
    void displayPersonInfo() const override;
};

#endif