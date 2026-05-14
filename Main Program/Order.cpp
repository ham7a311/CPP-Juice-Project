#include "Order.h"

Order::Order(Customer c) {
  // pass a Customer class member c as a parameter in constructor then assign it to our Customer class member customer
    customer = c;
    totalPrice = 0;
    status = "Pending";
    orderID = counter++;      // increase the counter everytime a new order is created
    
}


// size is the CUP size not Array/Vector size
void Order::addJuiceToOrder(Juice j, char size) {
    juices.push_back(make_pair(j, size));
    sizes.push_back(size);
}


double Order::calculateTotal() {
    totalPrice = 0;        // reset totalPrice everytime the function is called to avoid other orders' prices clashing with each other and result in unexpected output

    for (int i = 0; i < juices.size(); i++) {
        totalPrice += juices[i].calculatePrice(sizes[i]);
    }

    return totalPrice;
}


void Order::showOrderDetails() {
    cout << "Order ID: " << orderID << endl;

    customer.display();

    cout << "Your Order:" << endl;

    for (int i = 0; i < juices.size(); i++) {
        cout << "Juice: " << juices[i].getJuiceName() << endl;
        cout << "Size: " << sizes[i] << endl;
        cout << "Price: " << juices[i].calculatePrice(sizes[i]) << endl;
    }

    cout << "Total Price: " << calculateTotal() << endl;
    cout << "Status: " << status << endl;
}
