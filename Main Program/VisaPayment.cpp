#include "VisaPayment.h"

// constructor
VisaPayment::VisaPayment(double a, string cardNum)
    : Payment(a, "Visa") {

    if (cardNum.length() != 16) {
        throw invalid_argument("Visa card number must be 16 digits.");
    }

    cardNumber = cardNum;
}

// visa payment process
void VisaPayment::processPayment() {
    cout << "Visa payment of " << amount << " OMR completed." << endl;
}

// display visa payment details
void VisaPayment::displayPaymentInfo() const {
    Payment::displayPaymentInfo();
    cout << "Card Number    : **** **** **** "
         << cardNumber.substr(12, 4) << endl;
          //takes the last 4 digits from the card number , it start from the index 12
}
