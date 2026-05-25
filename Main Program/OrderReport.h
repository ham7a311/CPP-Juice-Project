#ifndef ORDERREPORT_H
#define ORDERREPORT_H

#include <iostream>
#include "Order.h"
using namespace std;

// Friend class used to generate reports for orders.
class OrderReport {
public:
    void printOrderReport(Order& order);
};

#endif