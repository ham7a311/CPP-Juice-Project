#include "CashPayment.h"

CashPayment::CashPayment(double a)
    : Payment(a, "Cash") {
}

void CashPayment::processPayment() {
    cout << "Cash payment of " << amount << " OMR completed." << endl;
}
