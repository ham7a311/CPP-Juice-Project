#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment {
public:
    CashPayment(double a);

    void processPayment() override;
};

#endif
