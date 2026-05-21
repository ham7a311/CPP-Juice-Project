#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include<string>
using namespace std;

class Payment{
protected:
  double amount;
  string paymentmethod;
public:
  Payment(double a,string method); //constructor

  virtual void processPayment()=0;
  virtual void displayPaymentInfo()const;

  virtual ~Payment();
};

#endif
