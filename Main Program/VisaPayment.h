#ifndef VISAPAYMENT_H
#define VISAPAYMENT_H

#include "Payment.h"

class VisaPayment : public Payment {
private:
    string cardNumber;

public:
    VisaPayment(double a, string cardNum); //constructer

    void processPayment() override;

    void displayPaymentInfo() const override;
};

#endif
