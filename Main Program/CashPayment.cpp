#include "CashPayment.h"

// constructor
CashPayment::CashPayment(double a, double cash)
    : Payment(a, "Cash") {

    if (cash < 0) {
        throw invalid_argument("Cash amount cannot be negative.");
    }

    cashGiven = cash;
}

// calculate the remaining change
double CashPayment::calculateChange() const {
    if (cashGiven > amount) {
        return cashGiven - amount;
    }
    else if (cashGiven == amount) {
        return 0;
    }
    else {
        return -1;
    }
}

// cash payment process
void CashPayment::processPayment() {
    double change = calculateChange();

    if (change == -1) {
        cout << "Cash payment unsuccessful. Not enough cash." << endl;
    }
    else {
        cout << "Cash payment successful." << endl;
        cout << "Bill amount : " << amount << " OMR" << endl;
        cout << "Cash given  : " << cashGiven << " OMR" << endl;
        cout << "Change      : " << change << " OMR" << endl;
    }
}
