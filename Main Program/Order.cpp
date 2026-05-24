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

        double price = juice.calculatePrice(size);
        //// Checks for invalid juice size before adding the price.
          if (price == -1) {
            cout << "Invalid size for " << juice.getJuiceName() << endl;
        } else {
                totalPrice += price;
                } 
    }
    return totalPrice;
}


void Order::showOrderDetails() {
    cout << *this;
}

int Order::getOrderID() const {
  return orderID;
}


// Returns the current status of the order.
string Order::getStatus() const {
    return status; 
}

void Order::completeOrder() {
  status = "Completed";

  
}



// Overloads << to print order details.
ostream& operator<<(ostream& out, Order& order) {
    out << "=================================" << endl;
    out << "Order ID: " << order.orderID << endl;
    out << "Status  : " << order.status << endl;
    out << "=================================" << endl;

    out << "Customer Information:" << endl;
    order.customer.displayPersonInfo();

    out << "Ordered Juices:" << endl;

    for (auto obj : order.juices) {
        Juice juice = obj.first;
        char size = obj.second;

        out << "- Juice: " << juice.getJuiceName() << endl;
        out << "  Size : " << size << endl;
        out << "  Price: " << juice.calculatePrice(size) << " OMR" << endl;
    }

    out << "---------------------------------" << endl;
    out << "Total Price: " << order.calculateTotal() << " OMR" << endl;
    out << "=================================" << endl;

    return out;
}