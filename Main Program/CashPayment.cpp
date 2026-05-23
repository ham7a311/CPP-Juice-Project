#include "CashPayment.h"

CashPayment::CashPayment(double a) //constructer
    : Payment(a, "Cash") {
}

void CashPayment::processPayment() { //cash payment process
    cout << "Cash payment of " << amount << " OMR completed." << endl;
}
