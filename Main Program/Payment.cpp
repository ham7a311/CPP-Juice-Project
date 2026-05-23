#include "Payment.h"

Payment::Payment(double a, string method) {
    if (a <= 0) {
        throw invalid_argument("Payment amount must be greater than zero.");
    }

    if (!isValidPaymentMethod(method)) {
        throw invalid_argument("Invalid payment method.");
    }

    amount = a;
    paymentMethod = method;
}

void Payment::showPaymentMethods() {
    cout << "Available Payment Methods:" << endl;
    cout << "1. Cash" << endl;
    cout << "2. Visa" << endl;
    cout << "3. American Express" << endl;
}

bool Payment::isValidPaymentMethod(string method) const {
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

Payment::~Payment() {
}
