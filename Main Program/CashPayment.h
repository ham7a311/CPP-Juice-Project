#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment {
private:
    double cashGiven;

public:
    CashPayment(double a, double cash); //cach a --> is the actual price, cash --> is the given .

    void processPayment() override;

    double calculateChange() const;
};

#endif
