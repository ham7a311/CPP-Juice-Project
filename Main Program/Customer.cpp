#include "Customer.h"

// Constructor
Customer::Customer(string n, string num) : Person(n, num) {
    customerID = counter++;
}

// Getter
int Customer::getCustomerID() const {
    return customerID;
}

// Place order
void Customer::placeOrder() const {
    cout << "Order placed by: " << name << endl;
    cout << "Order received!" << endl;
}

// Override display function from Person
void Customer::displayPersonInfo() const {
    cout << "-----------------------------" << endl;
    cout << "Customer Info" << endl;
    cout << "Customer ID : " << customerID << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phoneNumber << endl;
    cout << "-----------------------------" << endl;
}