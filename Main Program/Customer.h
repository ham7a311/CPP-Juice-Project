#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerID;
    string name;
    string phoneNumber;
    inline static int counter = 1; //becasue this class is written in a header file

public:
    // Constructor
    Customer(string n, string num = "00000000") {
        customerID = counter++;
        name = n;
        phoneNumber = num;
        
    }

    // Getters
    int getCustomerID() const { return customerID; }
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }

    // Setters
    void setName(string n) { name = n; }
    void setPhoneNumber(string num) { phoneNumber = num; }

    // Place order
    void place_order() const { 
        cout << "Order placed by: " << name << "\n";
        cout << "Order received!\n";
    }

    // Display
    void display() const {
        cout << "-----------------------------\n";
        cout << "Customer ID : " << customerID << "\n";
        cout << "Name        : " << name << "\n";
        cout << "Phone       : " << phoneNumber << "\n";
        cout << "-----------------------------\n";
    }
};
//int Customer::counter = 1; "deleted"
#endif
