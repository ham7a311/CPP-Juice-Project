#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"       // for display() function
#include "Juice.h"          // for calculatePrice(char size) function
#include <vector>            // to store juices and sizes
#include <iostream>
using namespace std;

class Order {
private:

    inline static int counter = 1;
    int orderID;
    Customer customer;      // use Customer class from Customer.h file to access display() function to display Customer Info
    vector<Juice> juices;   // stores juices
    vector<char> sizes;     // stores sizes(S/M/L or s/m/l)
    double totalPrice;      // totalPrice after adjusting everything (size, juice)
    string status;          // "pending" / "completed"

public:
    Order(Customer c);
    void addJuiceToOrder(Juice j, char size);
    double calculateTotal();
    void showOrderDetails();
};

#endif
