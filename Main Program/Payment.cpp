#include "Payment.h"

Payment::Payment(double a, string method) {
    if (a <= 0) {
        throw invalid_argument("Payment amount must be greater than zero.");
        //check if amount is valid
    }

    if (!isValidPaymentMethod(method)) {
        throw invalid_argument("Invalid payment method.");
        //check the payment method if it exsists 
    }

    amount = a;
    paymentMethod = method;
}

void Payment::showPaymentMethods() {
    //the avaliable paymentmethods for the customer
    cout << "Available Payment Methods:" << endl;
    cout << "1. Cash" << endl;
    cout << "2. Visa" << endl;
    cout << "3. American Express" << endl;
}

bool Payment::isValidPaymentMethod(string method) const {
    //it will return true only if one of these methods  chosen 
    return method == "Cash" ||
           method == "Visa" ||
           method == "American Express";
}

void Payment::displayPaymentInfo() const {
    cout << "-----------------------------" << endl;
    cout << "Payment Method : " << paymentMethod << endl;
    cout << "Amount         : " << amount << " OMR" << endl;
    cout << "-----------------------------" << endl;
}

//safe cleanup for payment objects
Payment::~Payment() {
}
