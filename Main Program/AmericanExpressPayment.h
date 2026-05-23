#ifndef AMERICANEXPRESSPAYMENT_H
#define AMERICANEXPRESSPAYMENT_H

#include "Payment.h"

class AmericanExpressPayment : public Payment {
private:
    string cardNumber;

public:
    AmericanExpressPayment(double a, string cardNum);

    void processPayment() override;

    void displayPaymentInfo() const override;
};

#endif
