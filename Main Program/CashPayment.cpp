#include "CashPayment.h"

// constructor
CashPayment::CashPayment(double a, double cash)
    : Payment(a, "Cash") {

    if (cash < 0) {
        throw invalid_argument("Cash amount cannot be negative.");
    }

    if (cash < a) {
        throw invalid_argument("Cash given is not enough.");
    }

    cashGiven = cash;
}

// calculate the remaining change
double CashPayment::calculateChange() const {
    return cashGiven - amount;
}

// cash payment process
void CashPayment::processPayment() {
    cout << "Cash payment successful." << endl;
    cout << "Bill amount : " << amount << " OMR" << endl;
    cout << "Cash given  : " << cashGiven << " OMR" << endl;
    cout << "Change      : " << calculateChange() << " OMR" << endl;
}