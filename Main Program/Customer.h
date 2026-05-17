#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Customer : public Person {
private:
    int customerID;
    inline static int counter = 1; //becasue this class is written in a header file
//the inline static in private because we dont want otherparts of the program to change it directly

public:
    // Constructor
    Customer(string n, string num = "00000000");


    // Getters
    int getCustomerID() const;


    // Place order
    void place_order() const ;


    // Display
    void displayCustomerInfo() const;
};
#endif
