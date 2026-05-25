#include "OrderReport.h"

// Prints a simple report for the order
void OrderReport::printOrderReport(Order& order) {

    cout << "========== Order Report ==========" << endl;
    cout << "Order ID : " << order.orderID << endl;
    cout << "Status   : " << order.status << endl;

    cout << "Customer :" << endl;
    order.customer.displayPersonInfo();

    cout << "Number of juices: " << order.juices.size() << endl;
    cout << "Total Price     : " << order.calculateTotal() << " OMR" << endl;
    cout << "==================================" << endl;
}