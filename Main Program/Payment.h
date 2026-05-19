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

  Virtual void processPayment()=0;
  Virtual void displayPaymentInfo()const;

  Virtual ~Payment();
};

#endif
