#ifndef JUICESHOP_H
#define JUICESHOP_H
#include<iostream>
#include<string>
#include<vector>
#include"Menu.h"
#include"Employee.h"
#include"Order.h"
#include"Payment.h"
#include"CashPayment.h"
#include"VisaPayment.h"
#include"AmericanExpressPayment.h"
using namespace std;
class JuiceShop{
  private:
     Menu menu;
     vector<Employee> employees;
     vector<Order> orders;
  public:
      Menu& getMenu();
      void addEmployee(Employee emp);
      void createOrder(Order ord);
      void displayOrders();
      void checkOrder(int id);
      void checkoutOrder(int id);
};
#endif
