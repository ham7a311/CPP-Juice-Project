#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"       // for display() function
#include "Juice.h"          // for calculatePrice(char size) function
#include <vector>
#include <utility>          // for using pairs in the vectors to store 
#include <iostream>
using namespace std;

class Order {
private:

       //the inline static in private because we dont want otherparts of the program to change it directly
        inline static int counter = 1;      //becasue this class is written in a header file
        int orderID;    // will be assigned to counter
        Customer customer;      // use Customer class from Customer.h file to access display() function to display Customer Info
        vector<pair<Juice, char>> juices;      // to store juice and size for each order
        double totalPrice;          // totalPrice after adjusting everything (size, juice)
        string status;      // "pending" / "completed"

public:
    Order(Customer c);
    void addJuiceToOrder(Juice j, char size);
    double calculateTotal();
    void showOrderDetails();
    int getOrderID();
};

#endif
