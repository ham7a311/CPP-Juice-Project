#include "Customer.h"

// Constructor
Customer::Customer(string n, string num) : Person(n, num){
    customerID = counter++;
}


//getter
int Customer::getCustomerID() const{
    return customerID;
}


//Place order
void Customer::placeOrder() const{
    cout << "Order placed by: " << name << endl;
    cout << "Order received!" << endl;
}


//Display Customer Info
void Customer::displayCustomerInfo() const{
    cout << "-----------------------------" << endl;
    cout << "CustomerID: " << customerID << endl;
    displayPersonInfo();
    cout << "-----------------------------" << endl;
}
