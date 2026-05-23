#include "AmericanExpressPayment.h"

// constructor
AmericanExpressPayment::AmericanExpressPayment(double a, string cardNum)
    : Payment(a, "American Express") {

    if (cardNum.length() != 15) {
        throw invalid_argument("American Express card number must be 15 digits.");
    }

    cardNumber = cardNum;
}

// american express payment process
void AmericanExpressPayment::processPayment() {
    cout << "American Express payment of " << amount << " OMR completed." << endl;
}

// display american express payment details
void AmericanExpressPayment::displayPaymentInfo() const {
    Payment::displayPaymentInfo();

    // starts from index 11 to show the last 4 digits
    cout << "Card Number    : **** ****** *"
         << cardNumber.substr(11, 4) << endl;
          //here we start from the index 11 since the card number of american express is 15 digits
}
