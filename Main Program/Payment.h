#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract class for different payment methods.
class Payment {
protected:
    double amount;
    string paymentMethod;

public:
    // Constructor
    Payment(double a, string method);

    // Displays the available payment methods.
    static void showPaymentMethods();

    // Checks if the payment method is valid.
    bool isValidPaymentMethod(string method) const;

    // Pure virtual function
    virtual void processPayment() = 0;

    // Display payment info
    virtual void displayPaymentInfo() const;

    // Virtual destructor
    virtual ~Payment();
};

#endif
