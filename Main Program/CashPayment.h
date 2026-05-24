#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment {
private:
    double cashGiven;

public:
    CashPayment(double a, double cash); // a --> is the given cach, cach --> is the actual price.

    void processPayment() override;

    double calculateChange() const;
};

#endif
