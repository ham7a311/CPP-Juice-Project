#include "Order.h"

Order::Order(Customer c) : customer(c) {
  // pass a Customer class member c as a parameter in constructor then assign it to our Customer class member customer
    totalPrice = 0;
    status = "Pending";
    orderID = counter++;      // increament the counter everytime a new order is created
    
}


// size is the CUP size not Array/Vector size
void Order::addJuiceToOrder(Juice j, char size) {
    juices.push_back(make_pair(j, size));    // push back j and size as an array since they are more than one element(pair), you can use make_pair or {}
}


double Order::calculateTotal() {
    totalPrice = 0;               // reset totalPrice everytime the function is called to avoid other orders' prices clashing with each other and result in unexpected output
    // auto helps you with writing the type instead of you writing it manually, without auto, we'll have to write for (pair<Juice, char> obj : juices) {...}
    for(auto obj: juices) {        
        auto juice = obj.first;
        auto size = obj.second;
        totalPrice += juice.calculatePrice(size);    // item.first --> Juice, item.second --> size(S/M/L or s/m/l)
    }

    return totalPrice;
}


void Order::showOrderDetails() {
    cout << "Order ID: " << orderID << endl;

    customer.displayCustomerInfo();

    cout << "Your Order:" << endl;

    for (auto obj : juices) {
        auto juice = obj.first;
        auto size = obj.second;
        cout << "Juice: " << juice.getJuiceName() << endl;
        cout << "Size: " << size << endl;
        cout << "Price: " << juice.calculatePrice(size) << endl;
    }

    cout << "Total Price: " << calculateTotal() << endl;
    cout << "Status: " << status << endl;
}

int Order::getOrderID(){
  return orderID;
}
